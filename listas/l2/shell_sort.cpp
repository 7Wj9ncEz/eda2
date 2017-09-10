#include <bits/stdc++.h>

using namespace std;

void shell(vector<int>& nums){
    int tam = nums.size();
    int gap = tam / 2;

    while(gap > 0){
        cout << "gap: " << gap << endl;
        for(int i=gap;i<tam;i++){
            int cur = nums[i];
            int j = i;

            while(j >= gap && nums[j - gap] > cur){
                nums[j] = nums[j - gap];
                j -= gap;
            }
            
            nums[j] = cur;

        }
        for(auto c : nums) cout << c << " "; cout << endl;

        gap /= 2;
    }
}

int main(){
    vector<int> nums { 4, 7, 11, 6, 10, 2, 8, 3, 9, 5, 1 };

    cout << "Vetor inicial" << endl;
    for(auto c : nums) cout << c << " "; cout << endl;

    shell(nums);

    cout << "Vetor ordenado" << endl;
    for(auto c : nums) cout << c << " "; cout << endl;

    return 0;
}
