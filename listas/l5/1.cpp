#include <bits/stdc++.h>

using namespace std;

vector<int> A = {2, 8, 15, 18};
vector<int> B = {3, 4, 27, 65};

int median(int n, int a, int b){
  int previous_n = n;
  int k = n/2;
  if(previous_n == 1) return min(A[a+k], B[b+k]);

  if(A[a+k] < B[b+k]) return median(k, a+(previous_n/2), b);
  else return median(k, a, b+(previous_n/2));
}

int main(){
  printf("Median is: %d\n", median(4, 0, 0));
  return 0;
}
