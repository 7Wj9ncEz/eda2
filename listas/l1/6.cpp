#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// global array to store the random numbers
ll v[1000010];

// variables used to generate a random number in get_rand() function
random_device rd;
mt19937 eng(rd());

// binary search
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

// get random number between (and including) low and high
int get_rand(int low, int high){
    uniform_int_distribution<> distribution(low, high);
    return distribution(eng);
}

// populate array with n numbers from (and including) low and high * 5
// after the array is populated, sort it
void get_n_rand(int n, int low, int high){
    for(int i=0;i<n;i++){
        v[i] = get_rand(low, 5 * high);
    }

    sort(v, v + n);
}

int main(){
    int number;
    cout << "Enter number of elements (up to 1000000): ";
    cin >> number;

    get_n_rand(number, 0, number * 5);

    // for(auto c : v) cout << c << " "; cout << endl;

    int random_idx = get_rand(0, number - 1);

    // binary search the element at a random position between 0 and size of array - 1
    int res = bs(number, v[random_idx]);

    if(res == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at %d\n", res);
    }

    return 0;
}
