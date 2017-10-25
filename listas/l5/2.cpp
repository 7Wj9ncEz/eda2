#include <bits/stdc++.h>

using namespace std;

int __merge(vector<int> v, vector<int> temp, int left, int mid, int right);

int merge_sort(vector<int> v, vector<int> temp, int left, int right){
  int mid, count = 0;
  if(right > left){
    mid = (right+left)/2;

    count = merge_sort(v, temp, left, mid);
    count += merge_sort(v, temp, mid+1, right);
    count += __merge(v, temp, left, mid+1, right);
  }

    return count;
}

int __merge(vector<int> v, vector<int> temp, int left, int mid, int right){
  int i, j, k;
  int count = 0;

  i = left; j = mid; k = left;
  while((i <= mid -1) && (j <= right)){
    if(v[i] <= v[j]){
      temp[k++] = v[i++];
    }else{
      temp[k++] = v[j++];
      count = count+(mid-1);
    }
  }

  while(i <= mid-1)
  temp[k++] = v[i++];

  while(j <= right)
  temp[k++] = v[j++];

  for(i = left; i <= right; i++)
  v[i] = temp[i];

  return count;
}

int merge_with_inversion(vector<int> v, int vsize){
    vector<int> temp(vsize);
    return merge_sort(v, temp, 0, vsize-1);
    return 1;
}


int main(){
  vector<int> v = {1, 23, 45, 34, 23, 54, 65, 7, 45};
  printf("Number of inversion are %d\n", merge_with_inversion(v, 9));
  return 0;
}
