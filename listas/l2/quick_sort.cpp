#include <bits/stdc++.h>

using namespace std;

int get_pivot_idx(int low, int high){
    return (low + high) / 2;
}

void quick_sort(vector<int>& v, int low, int high){
    cout << "low: " << low << " high: " << high << endl;
    if(low <= high){
        int i = low;
        int j = high;
        int pivot = v[get_pivot_idx(low, high)];
        
        while(i <= j){
            while(v[i] < pivot) i++;
            while(pivot < v[j]) j--;

            if(i <= j){
                swap(v[i], v[j]);
                i++;
                j--;
            }
        }

        quick_sort(v, low, j);
        quick_sort(v, i, high);
    }
}

int main(){
    vector<int> v { 1,5,2,8,3,7,4,6 };

    cout << "Vetor inicial: ";
    for(auto c : v) cout << c << " "; cout << endl;

    quick_sort(v, 0, v.size()-1);

    cout << "Vetor ordenado: ";
    for(auto c : v) cout << c << " "; cout << endl;

    return 0;
}
