#include <bits/stdc++.h>

using namespace std;

int opt[300][300];
vector<int> x { 10, 1, 7, 7 };
vector<int> s { 8, 4, 2, 1 };

int solve(){
    int n = x.size();

    for(int j=0;j<n;j++)
        opt[n-1][j] = min(x[n-1], s[j]);

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            opt[i][j] = max(opt[i+1][0], min(x[i], s[j]) + opt[i+1][j+1]);
        }
    }

    return opt[0][0];
}

int main(){

    cout << solve() << endl;

    return 0;
}
