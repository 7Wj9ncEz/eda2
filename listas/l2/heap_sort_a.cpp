#include <bits/stdc++.h>

using namespace std;

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
  int i, aux;
  for(i = ((int)v.size()-1)/2; i>= 0; i--){
    create_heap(v, i, (int)v.size()-1);
  }
  for(i = (int)v.size()-1; i >= 1; i--){
    aux = v[0];
    v[0] = v[i];
    v[i] = aux;
    create_heap(v, 0, i-1);
  }
}

void print_vector(vector<int> v){
  printf("[ ");
  for (int i=0; i<(int)v.size()-1; ++i){
    printf("%d ", v[i]);
  }
  printf("]\n");
}


int main(){
  vector<int> o = {8, 3, 35, 5, 2, 54, 6, 20, 30};
  print_vector(o);
  heap_sort(o);
  print_vector(o);
  return 0;
}
