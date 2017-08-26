#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

vector<ii> create_index_table(vector<int> v){
  int number_of_index = v.size() / 5;
  vector<ii> index_table;
  for(int i=0; i<5; ++i){
    index_table.push_back(make_pair(i*number_of_index, v[i*number_of_index]));
  }
  return index_table;
}

void print_index_table(vector<ii> index, vector<int> v){
  printf("Vector:\n");
  for(size_t i=0; i<v.size(); ++i){
    printf("Index: %d Element %d\n", i, v[i]);
  }
  printf("Index table:\n");
  for(size_t i=0; i<index.size(); i++){
    printf("Index: %d Value: %d\n", index[i].first, index[i].second);
  }
}

void search(vector<ii> index, vector<int> v, int element){
  int starting_index = 0;

  for(size_t i=0; i<index.size(); ++i){
    if(element <= index[i].second){
      i > 0 ? starting_index = index[i].first-1 : starting_index = index[i].first;
      break;
    }
    starting_index = index[i].first;
  }

  printf("Starting search from index %d\n", starting_index);
  for(size_t j = starting_index; j< v.size(); ++j){
    if(v[j] == element){
      printf("Element found at %d\n", j);
    }
  }
}

int main(){
  vector<int> elements{2, 4, 80, 100, 200, 350, 400, 560, 1200, 1300};
  vector<ii> index_table = create_index_table(elements);
  print_index_table(index_table, elements);
  search(index_table, elements, 2);
  return 0;
}
