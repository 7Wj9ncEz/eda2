#include <bits/stdc++.h>

using namespace std;

typedef struct no {
    int value;
    struct no *left, *right;
} no;

void insert(int num, no** node){
    if(*node==nullptr){
        no* new_node = (no*) malloc(sizeof(no));
        new_node->value = num;
        new_node->left = nullptr;
        new_node->right = nullptr;
        *node = new_node;
    }else{
        if((*node)->value > num){
            insert(num, &((*node)->left));
        }else{
            insert(num, &((*node)->right));
        }
    }
}

void pre_order(no* tree){
    if(tree == NULL){
        return;
    }else{
        printf("Pre-Order Value: %d\n", tree->value);
        pre_order(tree->left);
        pre_order(tree->right);
    }
}

void in_order(no* tree){
    if(tree == nullptr){
        return;
    }else{
        in_order(tree->left);
        printf("In-Order Value: %d\n", tree->value);
        in_order(tree->right);
    }
}

void pos_order(no* tree){
    if(tree == nullptr){
        return;
    }else{
        pos_order(tree->left);
        pos_order(tree->right);
        printf("Pos-Order Value: %d\n", tree->value);
    }
}

int main(){
    no* tree = nullptr;

    insert(4, &tree);
    insert(2, &tree);
    insert(5, &tree);
    insert(1, &tree);
    insert(3, &tree);
    insert(7, &tree);

    pre_order(tree);
    in_order(tree);
    pos_order(tree);

    return 0;
}
