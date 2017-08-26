#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > create_index_table(vector<int> v){
  int number_of_index = v.size() / 5;
  vector<pair<int, int> > index_table;
  for(int i=0; i<5; ++i){
    index_table.push_back(make_pair(i*number_of_index, v[i*number_of_index]));
  }
  return index_table;
}

void print_index_table(vector<pair<int, int> > index, vector<int> v){
  printf("VETOR\n");
  for(size_t i=0; i<v.size(); ++i){
    printf("Index: %d Element %d\n", i, v[i]);
  }
  printf("\nINDEX_TABLE\n");
  for(size_t i=0; i<index.size(); i++){
    printf("Index: %d Value: %d\n", index[i].first, index[i].second);
  }
}

int main(){
  vector<int> elementos {2, 4, 80, 100, 200, 350, 400, 560, 1200, 1300};
  vector<pair<int, int> > index_table = create_index_table(elementos);
  print_index_table(index_table, elementos);
  return 0;
}
