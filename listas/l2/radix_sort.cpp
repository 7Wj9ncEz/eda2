#include <bits/stdc++.h>

using namespace std;

void fill_vector(vector<string>&v , int n){
  string s = "abcdfeghijklkmnop";
  sort(s.begin(), s.end());
  do {
    v.push_back(s);
    n--;
  } while(next_permutation(s.begin(), s.end()) && n);
  printf("Size: %d\n", (int)v.size());
}

int find_maximum(vector<string> x){
  int max = 0;
  for(int i=0; i< (int)x.size(); ++i){
    if(max < (int) x[i].size()){
      max = x[i].size();
    }
  }
  return max;
}

void print_vector(vector<string> v){
  for(int i=0; i< (int)v.size(); ++i){
    printf("%s\n", v[i].c_str());
  }
}

void partial_sum(vector<int>& v){
  for(int i=1; i< (int) v.size(); ++i){
    v[i] += v[i-1];
  }
}

void counting_sort(vector<string>& v, int index){
  vector<string> aux(v.size());
  vector<int> count(257, 0);

  for(int i=0; i< (int)v.size(); ++i){
    count[index < (int) v[i].size() ? (int)(unsigned char) v[i][index]+1 : 0]++;
  }

  partial_sum(count);

  for(int i = (int) v.size() - 1; i >= 0; --i){
    aux[count[index < (int) v[i].size()? (int)(unsigned char) v[i][index]+1 : 0] - 1] = v[i];
    count[index < (int) v[i].size()? (int)(unsigned char)v[i][index] +1 : 0]--;
  }

  for(int i = 0; i < (int)v.size(); ++i){
    v[i] = aux[i];
  }

  count.clear();
  aux.clear();
}

void radix_sort(vector<string>& v){
  int max = find_maximum(v);
  for(int i = max; i > 0; --i){
    counting_sort(v, i-1);
  }
}

int main(){
    vector<string> v;
    fill_vector(v, 1000000);
    radix_sort(v);
    return 0;
}
