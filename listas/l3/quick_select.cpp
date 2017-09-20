#include <bits/stdc++.h>

#define N_GROUPS 7

using namespace std;

void print(vector<int> v, int from, int to, bool newline = true){
    cout << "[";
    for(int i=from;i<to;i++){
        if(i != from) printf(" ");
        cout << v[i];
    }
    cout << "]";
    if(newline) cout << endl;
}

int get_median(vector<int> v, int from, int to){
    vector<int> temp;
    for(int i=from;i<to;i++){
        temp.push_back(v[i]);
    }

    sort(temp.begin(), temp.end());

    int median = temp[(temp.size()-1) / 2];

    return median;
}

vector<int> get_mom(vector<int> v){
    vector<int> medians;
    int n = v.size();

    for(int i=0; i<n; i += N_GROUPS){
        int m = get_median(v, i, min(i + N_GROUPS, n));
        medians.push_back(m);
    }

    return medians;
}

int quick_select(vector<int> v, int k){
    int n = v.size();


    vector<int> medians = v;

    do{
        medians = get_mom(medians);
    }while(medians.size() > 1);

    int MOM = medians[0];

    vector<int> L, R;

    for(int i=0;i<n;i++){
        if(v[i] < MOM) L.push_back(v[i]);
        else if(v[i] > MOM) R.push_back(v[i]);
    }

    if((int)L.size() == k-1)
        return MOM;
    else if((int)L.size() > k-1)
        return quick_select(L, k);

    return quick_select(R, k - L.size() - 1);
}

int main(){
    vector<int> v { 9,4,8,3,7,1,2,6,5 };

    print(v, 0, v.size());

    cout << "Median: " << quick_select(v, (v.size() + 1)/2) << endl;

    return 0;
}
