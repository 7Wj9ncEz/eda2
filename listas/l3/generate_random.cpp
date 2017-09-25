#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// global array to store the random numbers
ll v[1000];

// variables used to generate a random number in get_rand() function
random_device rd;
mt19937 eng(rd());

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
    get_n_rand(1000, 0, 5000);

    printf("vector<int> v = {");
    
    for(int i=0;i<1000;i++){
        if(i) printf(", ");
        printf("%lld", v[i]);
    }

    printf("};");


    return 0;
}
