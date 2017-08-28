**Lista 1 - Estruturas de Dados 2**
**Prof. Maurício Serrano**
**serr.mau@gmail.com**

**A lista deve ser feita em duplas. Entrega: 28/08, via Moodle**

**Lista de Exercícios - Lógica e Algoritmos de Busca**

**Esta parte da lista de exercícios é composta por exercícios teóricos que abordam raciocínio lógico.**

**1. Três músicos, João, Antônio e Francisco, tocam harpa, violino e piano. Contudo, não se sabe quem toca o quê. Sabe-se que o Antônio não é o pianista. Mas o pianista ensaia sozinho na Terça. O João ensaia com o Violoncelista às Quintas. Quem toca o quê?**

**2. No antigo Egito, havia um prisioneiro numa cela com duas saídas, cada uma delas com um guarda. Cada saída dava para um corredor diferente em que um dava para o campo e, portanto, para a liberdade e o outro para um fosso de crocodilos. Só os guardas sabiam qual a saída certa, mas um deles dizia sempre a verdade e outro mentia sempre. O prisioneiro não sabia nem qual a saída certa nem qual o guarda que dizia a verdade. Qual a pergunta (e uma só pergunta) que o prisioneiro deveria fazer a um dos guardas ao acaso, para saber qual a porta certa?**

**3. Três pessoas se registram em um hotel. Elas pagam R$30,00 ao gerente e vão para seus quartos. O gerente nota que a diária é de R$25,00 e entrega R$5,00 ao mensageiro do hotel para ele devolver aos hóspedes. No caminho, o mensageiro conclui que seria complicado dividir R$5,00 entre 3 pessoas, então ele embolsa R$2,00 e entrega R$1,00 para cada pessoa. Agora, cada um pagou R$10,00 e pegou R$1,00 de volta. Então, cada um pagou R$9,00, totalizando R$27,00. O mensageiro tem R$2, totalizando R$29. Onde está o outro R$1,00?**

**Esta parte da lista de exercícios é composta por exercícios práticos que abordam Algoritmos de Busca.**

**4. Implemente uma busca sequencial com índice primário. Explique seus algoritmos de inserção e de remoção.**

**5. Implemente as três travessias em uma árvore binária: Pré-ordem, Em-ordem e pós-ordem.**

``` c++
// inserção na árvore binária
void insert(int num, no** node){
    if(*node==nullptr){
        no* new_node = (no*) malloc(sizeof(no));
        new_node->value = num;
        new_node->left = nullptr;
        new_node->right = nullptr;
        *node = new_node;
    }
    else{
        if((*node)->value > num){
            insert(num, &((*node)->left));
        }else{
            insert(num, &((*node)->right));
        }
    }
}

// travessia pré-ordem
void pre_order(no* tree){
    if(tree == NULL){
        return;
    }else{
        printf("Pre-Order Value: %d\n", tree->value);
        pre_order(tree->left);
        pre_order(tree->right);
    }
}

// travessia em ordem
void in_order(no* tree){
    if(tree == nullptr){
        return;
    }else{
        in_order(tree->left);
        printf("In-Order Value: %d\n", tree->value);
        in_order(tree->right);
    }
}

// travessia pós ordem
void pos_order(no* tree){
    if(tree == nullptr){
        return;
    }else{
        pos_order(tree->left);
        pos_order(tree->right);
        printf("Pos-Order Value: %d\n", tree->value);
    }
}

// teste das funções
int main(){
    no* tree = nullptr;

    insert(4, &tree);
    insert(2, &tree);
    insert(5, &tree);
    insert(1, &tree);
    insert(3, &tree);
    insert(7, &tree);

    pre_order(tree);
    in_order(tree);
    pos_order(tree);

    return 0;
}
```

**6. Em uma busca por interpolação, utilize o cálculo dado em sala. Teste o tempo gasto pela busca para encontrar um valor em um vetor de 10, 25, 50, 100, 500, mil, dez mil, cem mil e um milhão de posições preenchidas com números randômicos. A taxa de crescimento é ou não é menor que a ordem de log(n)?**

| Número de elementos do vetor (n) | log(n) | Tempo de geração do vetor | Tempo da busca | Média do tempo total de 5 execuções (gerar lista + busca binária) | Taxa de crescimento (em relação ao anterior) | Taxa de crescimento de log n (com relação ao anterior) |
| :-----: | :----: | :----: | :-----: | :-----: | :---: | :---: |
| 10      | 3.321  | 0.005s | 0.001s | 0.006s | ----- | ----  |
| 25      | 4.643  | 0.006s | 0.001s | 0.007s | 1.428 | 1.343 |
| 50      | 5.643  | 0.003s | 0.003s | 0.006s | 0.7 | 1.215 |
| 100     | 6.643  | 0.006s | 0.001s | 0.007s | 1.571 | 1.177 |
| 500     | 8.965  | 0.005s | 0.002s | 0.007s | 1.000 | 1.349 |
| 1000    | 9.965  | 0.003s | 0.001s | 0.004s | 0.09 | 1.111  |
| 10000   | 13.287  | 0.011s | 0.002s | 0.013s | 1.00 | 1.333 |
| 100000  | 16.609 | 0.039s | 0.005s | 0.044s | 12.999 | 1.25 |
| 1000000 | 19.931 | 0.373s | 0.002s | 0.375s | 0.307 | 1.2  |



**Bom trabalho!**
