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
