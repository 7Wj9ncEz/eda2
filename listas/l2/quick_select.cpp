#include <bits/stdc++.h>

using namespace std;

int get_median_out_of_5(vector<int> v){
    // use insertion sort of array of 5 elements
    for(int i=1;i < (int)v.size();i++){
        int j = i;

        while(j && (v[j] < v[j-1])){
            swap(v[j], v[j-1]);
            j--;
        }
    }

    // return median of this array
    return v[(v.size() - 1)/2];
}

int get_mom(vector<int> v){
    vector<int> medians;

    for(int i=0;i<(int)v.size();i+=5){
        // divide into sets of 5
        vector<int> group;
        for(int j=i;j < i+5 && j < (int)v.size();j++){
            group.push_back(v[j]);
        }

        medians.push_back(get_median_out_of_5(group));
    }

    if(medians.size() > 5){
        return get_mom(medians);
    }

    return get_median_out_of_5(medians);
}

// mom = median of medians
int k_smallest(vector<int> v, int k){
    int mom = get_mom(v);

    if(v.size() <= 1) return mom;

    vector<int> left_values, right_values;

    for(auto c : v){
        if(c < mom) left_values.push_back(c);
        else if(c > mom) right_values.push_back(c);
    }

    int count_left = left_values.size();

    if(count_left > k - 1)
        return k_smallest(left_values, k);
    else if(count_left < k - 1)
        return k_smallest(right_values, k - count_left - 1);

    return mom;
}

int k_smallest(vector<int> v, int k, int low, int high){
    vector<int> temp;

    for(int i=low;i<=high;i++){
      temp.push_back(v[i]);
    }

    return k_smallest(temp, k);
}
//
// int main(){
//     int n;
//     vector<int> v;
//
//     cout << "Enter number of elements: ";
//     cin >> n;
//     cout << endl;
//
//     cout << "Enter elements: ";
//     cout << endl;
//
//     for(int i=0;i<n;i++){
//         int num;
//         cin >> num;
//         v.push_back(num);
//     }
//
//     int res =  k_smallest(v, (v.size() + 1) / 2);
//
//     cout << endl << "array: ";
//     for(auto c : v) cout << c << " ";
//     cout << endl << endl;
//
//     cout << "Median of array: " << res << endl;
//
//     return 0;
// }
