###### Universidade de Brasília - Faculdade Gama

###### Disciplina: Estrutura de Dados e Algoritmos 2

###### Professor: Maurício Serrano

###### Alunos:
  - Victor Matias Navarro - 14/0032932
  - Vítor Barbosa de Araujo - 14/0033149

###### Assunto: Lista de exercícios 1

#### 4. Implemente uma busca sequencial com índice primário. Explique seus algoritmos de inserção e de remoção.

``` c++
#include <bits/stdc++.h>
#define EMPTY -1

using namespace std;
using ii = pair<int, int>;

// create index table with given gap
vector<ii> create_index_table(vector<int>& v, int gap){
    sort(v.begin(), v.end());

    int index_size = v.size() / gap;
    int number_of_index = v.size() / index_size;
    vector<ii> index_table;

    for(int i=0; i < index_size; i++){
        index_table.push_back(ii(i * number_of_index, v[i * number_of_index]));
    }

    return index_table;
}

void print_index_table(vector<ii> index, vector<int> v){
    printf("Vector:\n");
    for(int i=0; i < (int)v.size(); i++){
        printf("Index: %d Element %d\n", i, v[i]);
    }

    printf("\nIndex table:\n");
    for(int i=0; i < (int)index.size(); i++){
        printf("Index: %d Value: %d\n", index[i].first, index[i].second);
    }
    printf("\n");
}

// returns a pair:
// - starting index (got from index table) to search in the array of elements
// - position of the element, if found
// - if not found, return -1 in the second parameter
ii search(vector<ii>& index, vector<int>& v, int element, bool suppress_log = false){

    if(not suppress_log)
        printf("Looking for [%d]\n", element);

    int starting_index = 0;

    for(int i=0; i < (int)index.size(); i++){
        if(element <= index[i].second){
            starting_index = i > 0 ? index[i-1].first : index[i].first;
            break;
        }

        starting_index = index[i].first;
    }

    if(not suppress_log)
        printf("Started search from index %d\n", starting_index);

    int index_found = -1;

    for(int j = starting_index; j < (int)v.size(); j++){
        if(v[j] == element){
            index_found = j;
            break;
        }
    }

    if(not suppress_log){
        if(index_found != -1){
            printf("Element [%d] found at position [%d]\n", element, index_found);
        }
        else {
            printf("Element [%d] not found\n", element);
        }
    }

    return ii(starting_index, index_found);
}

// insert elements in this way:
// - if there is a empty slot, insert it in the slot
// - else, insert in the correct position and rearrange the indexes in the index table
void insert(vector<ii>& index_table, vector<int>& v, int element, int gap){
    ii result = search(index_table, v, element, true);

    int start_from = result.first == -1 ? 0 : result.first;
    bool inserted = false;
    bool found_empty_space = false;
    bool found_element = false;

    for(int i=start_from; i<v.size(); i++){
        if(v[i] >= element){
          if(v[i] == EMPTY){
            found_empty_space = true;
            inserted = true;
            v[i] = element;
            printf("Element [%d] inserted\n", element);
            break;
          }else{
            v.insert(v.begin()+i, element);
            printf("Element [%d] inserted\n", element);
            inserted = true;
            break;
          }
        }
    }

    if(not inserted){
      v.push_back(element);
    }
    else if(inserted && !found_empty_space){
        for(int i=0; i<index_table.size(); i++){
            index_table[i].second = v[index_table[i].first];
        }
    }

    if(v.size() % gap == 1){
        index_table.push_back(ii(v.size()-1, v.back()));
    }
}

// remove element from the array and rebuild the table if the variable rebuild_table in enabled
void remove(vector<ii>& index_table, vector<int>& v, int element, bool rebuild_table){
    ii result = search(index_table, v, element, true);

    if(result.second == -1){
        printf("This element does not exist\n");
        return;
    }

    if(rebuild_table){
        v.erase(v.begin() + result.second);
        index_table = create_index_table(v, 2);
    }
    else{
        v[result.second] = EMPTY;
    }
}

int main(){
		int gap = 2;
    vector<int> elements = { 2, 4, 80, 100, 200, 350, 400, 560, 1200, 1300 };
    vector<ii> index_table = create_index_table(elements, gap);

    int option;

    do{
        cout << "1 - Insert element" << endl;
        cout << "2 - Remove element" << endl;
        cout << "3 - Search element" << endl;
        cout << "4 - Print index table and array of elements" << endl;
        cout << "0 - Quit" << endl;
        cout << endl << "Choose an option: ";

        cin >> option;

        switch(option){
            case 1:
                {
                    int to_insert;
                    printf("Add element: ");
                    cin >> to_insert;

                    insert(index_table, elements, to_insert, gap);
                    break;
                }
            case 2:
                {
                    int to_remove;
                    printf("Remove element: ");
                    cin >> to_remove;

                    cout << "Do you wish to rebuild the index table? (1 - yes / 2 - no)" << endl;
                    int rebuild;
                    cin >> rebuild;

                    remove(index_table, elements, to_remove, rebuild == 1 ? true : false);
                    break;
                }
            case 3:
            {
                int to_search;
                cout << "Search element: ";
                cin >> to_search;

                ii search_result = search(index_table, elements, to_search);
                break;
            }
            case 4:
                print_index_table(index_table, elements);
                break;
            case 0:
                break;

        }
    }while(option != 0);

    return 0;
}
```

#### 5. Implemente as três travessias em uma árvore binária: Pré-ordem, Em-ordem e pós-ordem.

``` c++
#include <bits/stdc++.h>

using namespace std;

typedef struct no {
    int value;
    struct no *left, *right;
} no;

void insert(int num, no** node){
    if(*node==nullptr){
        no* new_node = (no*) malloc(sizeof(no));
        new_node->value = num;
        new_node->left = nullptr;
        new_node->right = nullptr;
        *node = new_node;
    }else{
        if((*node)->value > num){
            insert(num, &((*node)->left));
        }else{
            insert(num, &((*node)->right));
        }
    }
}

void pre_order(no* tree){
    if(tree == NULL){
        return;
    }else{
        printf("Pre-Order Value: %d\n", tree->value);
        pre_order(tree->left);
        pre_order(tree->right);
    }
}

void in_order(no* tree){
    if(tree == nullptr){
        return;
    }else{
        in_order(tree->left);
        printf("In-Order Value: %d\n", tree->value);
        in_order(tree->right);
    }
}

void pos_order(no* tree){
    if(tree == nullptr){
        return;
    }else{
        pos_order(tree->left);
        pos_order(tree->right);
        printf("Pos-Order Value: %d\n", tree->value);
    }
}

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

#### 6. Em uma busca por interpolação, utilize o cálculo dado em sala. Teste o tempo gasto pela busca para encontrar um valor em um vetor de 10, 25, 50, 100, 500, mil, dez mil, cem mil e um milhão de posições preenchidas com números randômicos. A taxa de crescimento é ou não é menor que a ordem de log(n)?**

``` c++
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// global array to store the random numbers
ll v[1000010];

// variables used to generate a random number in get_rand() function
random_device rd;
mt19937 eng(rd());

// binary search
// return idx of found element, or -1 otherwise
int bs(int n, int val){
    printf("\nLooking for %d\n", val);

    int low = 0, high = n - 1;

    while(low < high){
        if(v[low] > val || v[high] < val) return -1;

        ll middle = low + ((high - low) * (val - v[low])) / (v[high] - v[low]);
        if(v[middle] == val) return middle;

        if(v[middle] < val) low = middle + 1;
        else high = middle - 1;
    }

    return -1;
}

// get random number between (and including) low and high
int get_rand(int low, int high){
    uniform_int_distribution<> distribution(low, high);
    return distribution(eng);
}

// populate array with n numbers from (and including) low and high * 5
// after the array is populated, sort it
void get_n_rand(int n, int low, int high){
    for(int i=0;i<n;i++){
        v[i] = get_rand(low, 5 * high);
    }

    sort(v, v + n);
}

int main(){
    int number;
    cout << "Enter number of elements (up to 1000000): ";
    cin >> number;

    get_n_rand(number, 0, number * 5);

    // for(int i = 0 ; i < number; ++i) cout << v[i] << " "; cout << endl;

    int random_idx = get_rand(0, number - 1);

	// cout << "Random_idx: " << random_idx << endl; 	

    // binary search the element at a random position between 0 and size of array - 1
    int res = bs(number, v[random_idx]);

    if(res == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at %d\n", res);
    }

    return 0;
}
```

| Número de elementos do vetor (n) | log(n) | Tempo de geração do vetor | Tempo da busca | Média do tempo total de 5 execuções | Taxa de crescimento do tempo da busca | Taxa de crescimento do tempo total | Taxa de crescimento de log n  |
| :-----: | :----: | :----: | :-----: | :-----: | :---: | :-: | :---: |
| 10      | 3.321  | 0.005s | 0.001s | 0.006s | ----- |----- |----  |
| 25      | 4.643  | 0.006s | 0.001s | 0.007s | 1.000 | 1.166 |1.343 |
| 50      | 5.643  | 0.003s | 0.003s | 0.006s | 3.000 | 0.857 |1.215 |
| 100     | 6.643  | 0.006s | 0.001s | 0.007s | 0.333 | 1.166 |1.177 |
| 500     | 8.965  | 0.005s | 0.002s | 0.007s | 2.000 | 1.000 |1.349 |
| 1000    | 9.965  | 0.003s | 0.001s | 0.004s | 0.500 | 0.571 |1.111 |
| 10000   | 13.287 | 0.011s | 0.002s | 0.013s | 2.000 | 3.250 |1.333 |
| 100000  | 16.609 | 0.039s | 0.005s | 0.044s | 2.500 | 3.384 |1.25  |
| 1000000 | 19.931 | 0.373s | 0.002s | 0.375s | 0.400 | 8.522 |1.2   |

Com elementos gerados aleatoriamente, a taxa de crescimento da busca por interpolação é,
quase sempre, maior do que a taxa de crescimento da função log n. Isso implica que a utilização de busca por interpolação em vetores com elementos sem uma taxa de crescimento constante é pior do que a utilização da busca binária comum.
