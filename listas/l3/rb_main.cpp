#include "rb.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v { 41, 5, 90, 39, 79, 45, 81, 65, 59, 66 };

    RBTree* tree = new RBTree();

    for(auto c : v){
        printf("Inserting %d\n", c);
        tree->insert(c);

        tree->pre_order(tree->root);
        cout << endl;
    }

    cout << endl << endl;
    tree->pre_order(tree->root);

    return 0;
}
