#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll v[1000010];
random_device rd;
mt19937 eng(rd());

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

int get_rand(int low, int high){
    uniform_int_distribution<> distribution(low, high);
    return distribution(eng);
}

void get_n_rand(int n, int low, int high){
    for(int i=0;i<n;i++){
        v[i] = get_rand(low, high);
    }

    sort(v, v + n);
}

int main(){
    int number;
    cout << "Enter number of elements: ";
    cin >> number;

    get_n_rand(number, 0, number * 5);

    // for(auto c : v) cout << c << " "; cout << endl;

    int random_idx = get_rand(0, number - 1);
    int res = bs(number, v[random_idx]);

    if(res == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at %d\n", res);
    }

    return 0;
}
