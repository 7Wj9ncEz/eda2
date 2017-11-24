###### Universidade de Brasília - Faculdade Gama

###### Disciplina: Estrutura de Dados e Algoritmos 2

###### Professor: Maurício Serrano

###### Alunos:
  - Victor Matias Navarro - 14/0032932
  - Vítor Barbosa de Araujo - 14/0033149

###### Assunto: Lista de exercícios 6

#### Questão 1

* __(a)__ Considerando o caso em que se tenha uma sequência de pesos 4, 7, 4. Esse algoritmo retornaria o resultado 7 (escolhendo o nó do meio), porém o máximo peso possível seria escolhendo o primeiro e o terceiro nós, totalizando 8.

* __(b)__ Considerando o caso em que se tenha um sequência de pesos 4, 2, 2, 5. Nesse caso o resultado seria 7 (máximo entre 6 - nós impares - e 7 - nós pares). Porém o resultado correto seria 9, escolhendo o primeiro e o último nós.

* __( c)__

```python
# considering a simple graph where two adjacent elements in list are connected

def f(n):
    if n == -1:
        return 0
    # if there is only first item, return its weight
    if n == 0:
        return weights[0]

    # get maximum between not choosing weights[i] (thus getting f(i-1) + 0)
    #       and choosing weights[i] (thus adding weights[i] with f(i-2) --> because you have to skip its neighbor)
    return max(f(n-1), weights[n] + f(n-2))

global weights
weights = [4,2,5,2]

print('Maximum weight of {} is {}'.format(weights, f(len(weights) - 1)))
```

#### Questão 5

A solução seria formada utilizando a função `opt` abaixo, onde `opt(i)` corresponde à melhor segmentação do prefixo que contém as primeiras i letras da palavra dada (e `quality(a, b)` corresponde à qualidade da palavra formada pelos caracteres começando de a e terminando em b). A solução se encontra em `opt(n)`, onde n é o tamanho da palavra dada.

``` python
def opt(i):
    if i < 0:
      return 0
    ans = 0

    for j in range(0, i+1):
        ans = max(ans, opt(j-1) + quality(j, n))

    return ans
```

#### Questão 6

``` python
INF = 2**25
text = ['Call','me','Ishmael.',
        'Some','years','ago',
        'never', 'mind', 'how', 'long', 'precisely,',
        'having', 'little', 'or', 'no', 'money', 'in', 'my', 'purse,',
        'and', 'nothing', 'particular', 'to', 'interest', 'me', 'on', 'shore,',
        'I' 'thought', 'I', 'would', 'sail', 'about', 'a', 'little',
        'and', 'see', 'the', 'watery', 'part', 'of', 'the', 'world.'
        ]
n = len(text)
L = 40

def pretty_print():
    s = [[INF for i in range(n)] for j in range(n)]

    for i in range(n):
        for j in range(i+1, n):
            line_length = 0
            for k in range(i,j+1):
                line_length += len(text[k])
            s[i][j] = line_length if line_length <= L else INF

    opt = [INF for i in range(n)]
    opt[0] = 0

    for k in range(n):
        for j in range(k+1):
            opt[k] = min(opt[k], s[j][k] ** 2 + opt[j-1])

    return opt[n-1]

print(pretty_print())
```
