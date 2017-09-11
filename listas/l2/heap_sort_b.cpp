#include <bits/stdc++.h>

using namespace std;

random_device rd;
mt19937 eng(rd());

int get_random(int low, int high){
  uniform_int_distribution<> distribution(low, high);
  return distribution(eng);
}

void fill_vector(vector<int>& v, int low, int high, int n){
  for(int i=0; i<n; i++){
    v.push_back(get_random(low, high));
  }
}

void create_heap(vector<int>& v, int inicio, int fim){
  int aux = v[inicio];
  int j = inicio*2+1;  // pega primeiro filho
  while(j <= fim){  // se eu ainda estou no range
    if(j < fim){
      if(v[j] < v[j+1]){ // pega o maior filho
        j = j+1;
      }
    }
    if(aux < v[j]){
      v[inicio] = v[j];
      inicio = j;
      j = 2*inicio+1;
    }else{
      j = fim+1;
    }
  }
  v[inicio] = aux;
}

void heap_sort(vector<int>& v){
  vector<int> aux_v;
  int i;
  for(i = ((int)v.size()-1)/2; i>= 0; i--){
    create_heap(v, i, (int)v.size()-1);
  }
  for(i = (int)v.size()-1; i >= 1; i--){
    aux_v.insert(aux_v.begin(), *v.begin());
    v[0] = v[i];
    create_heap(v, 0, i-1);
  }
  aux_v.insert(aux_v.begin(), *v.begin());
  v = aux_v;
}

void print_vector(vector<int> v){
  printf("[ ");
  for (int i=0; i<(int)v.size()-1; ++i){
    printf("%d ", v[i]);
  }
  printf("]\n");
}


int main(){
  vector<int> o;
  fill_vector(o, 0, 10000000, 100000);
  heap_sort(o);
  return 0;
}
