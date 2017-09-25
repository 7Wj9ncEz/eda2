#include <bits/stdc++.h>

using namespace std;

typedef struct no {
    int value, height;
    struct no *left, *right;
} no;

int get_height(no* node){
  if(node == nullptr) return 0;
  return node->height;
}

void rotate_right(no** node){
  no* left_child = (*node)->left;
  no* right_children_from_left_children = left_child->right;

  left_child->right = *(node);
  (*node)->left = right_children_from_left_children;

  (*node)->height = 1 + max(get_height((*node)->left), get_height((*node)->right));
  *node = left_child;
  left_child->height = 1 + max(get_height((*node)->left), get_height((*node)->right));
}

void rotate_left(no** node){
  no* right_child = (*node)->right;
  no* left_children_from_right_children = right_child->left;

  right_child->left = *(node);
  (*node)->right = left_children_from_right_children;

  (*node)->height = 1 + max(get_height((*node)->left), get_height((*node)->right));
  *node = right_child;
  right_child->height = 1 + max(get_height((*node)->left), get_height((*node)->right));
}

int get_balance_factor(no* node){
  if(node == nullptr) return 0;
  return get_height(node->left) - get_height(node->right);
}

void insert(int num, no** node){
    if(*node==nullptr){
        no* new_node = (no*) malloc(sizeof(no));
        new_node->value = num;
        new_node->left = nullptr;
        new_node->right = nullptr;
        new_node->height = 1;
        *node = new_node;
    }else{
        if((*node)->value > num){
            insert(num, &((*node)->left));
        }
        if((*node)->value < num){
            insert(num, &((*node)->right));
        }
        (*node)->height = 1 + max(get_height((*node)->left), get_height((*node)->right));
        int balance = get_balance_factor(*node);

        if(balance > 1){
          if(num < (*node)->left->value){
            rotate_right(node);
          }else if(num > (*node)->left->value){
            rotate_left(&(*node)->left);
            rotate_right(node);
          }
        }
        if(balance < -1){
          if(num < (*node)->right->value){
            rotate_right(&(*node)->right);
            rotate_left(node);
          }else{
            rotate_left(node);
          }
        }
    }
}

void in_order(no* tree){
    if(tree == nullptr){
        return;
    }else{
        in_order(tree->left);
        printf("In-Order Value: %d Height: %d Balance: %d\n", tree->value, get_height(tree), get_balance_factor(tree));
        in_order(tree->right);
    }
}


int main(){
  no* arvore = nullptr;
  insert(10, &arvore);
  insert(7, &arvore);
  insert(6, &arvore);
  insert(8, &arvore);
  insert(12, &arvore);
  insert(11, &arvore);
  insert(13, &arvore);
  in_order(arvore);
  return 0;
}
