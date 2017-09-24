// FIXME create class and add node* root

#include <bits/stdc++.h>
#define RED 0
#define BLACK 1

using namespace std;

typedef struct _n {
    struct _n *left, *right, *p;
    int color, value;
} node;

node* parent(node* n){
    return n->p; 
}

node* grandpa(node* n){
    if(n && parent(n))
        return parent(parent(n));
    return nullptr;
}

node* uncle(node* n){
    node* g = grandpa(n);

    if(g == nullptr)
        return nullptr;
    if(g->left == parent(n))
        return g->right;
    return g->left;
}

void case1(node* n);
void case2(node* n);
void case3(node* n);
void case4(node* n);
void case5(node* n);
void rotate_left(node* n);
void rotate_right(node* n);

void print(node* n){
    if(n == nullptr) printf("Null\n");
    else{
        printf("Color: %s\n", (n->color ? "BLACK" : "RED"));
        printf("Val: %d\n", n->value);
    }
}

const char* printc(int c){
    return c ? "BLACK" : "RED";
}

void pre_order(node* tree){
    if(tree == NULL){
        return;
    }else{
        printf("Node [%d, %s]: ", tree->value, printc(tree->color));

        if(tree->p)
            printf("p[%d, %s], ", parent(tree)->value, printc(parent(tree)->color));
        else
            printf("p[null], ");

        if(tree->left)
            printf("l[%d, %s], ", tree->left->value, printc(tree->left->color));
        else
            printf("l(null), ");
        if(tree->right)
            printf("r[%d, %s]\n", tree->right->value, printc(tree->right->color));
        else
            printf("r(null)\n");
        pre_order(tree->left);
        pre_order(tree->right);
    }
}

void insert(int val, node** tree, node* par){
    if(*tree == nullptr){
        node* n = (node*)malloc(sizeof(node));
        n->color = RED;
        n->value = val;
        n->left = nullptr;
        n->right = nullptr;
        n->p = par;

        *tree = n;

        case1(*tree);
    }
    else{
        if(val > (*tree)->value){
            insert(val, &((*tree)->right), *tree);
        }
        else{
            insert(val, &((*tree)->left), *tree);
        }
    }
}

void case1(node* n){
    printf("case 1 on node [%d]\n", n->value);
    if(parent(n) == nullptr){
        n->color = BLACK;
    }
    else{
        case2(n);
    }
}

void case2(node* n){
    printf("case 2 on node [%d]\n", n->value);
    if(parent(n)->color == BLACK){
        return;
    }
    else{
        case3(n);
    }
}

void case3(node* n){
    printf("caso 3 on node [%d]\n", n->value);
    node* p = parent(n);
    node* u = uncle(n);
    node* g = grandpa(n);

    printf("p: [%d, %s],", p->value, printc(p->color));
    if(u != nullptr)
        printf(" u: [%d, %s],", u->value, printc(u->color));
    else
        printf("u[null],");
    
    printf("g: [%d, %s]\n", g->value, printc(g->color));

    if(u != nullptr && u->color == RED){
        p->color = BLACK;
        u->color = BLACK;
        g->color = RED;

        case1(g); 
    }
    else{
        printf("c3: go to case4\n");
        case4(n);
    }
}

void case4(node* n){
    printf("case 4 on node [%d]\n", n->value);
    node* p = parent(n);
    node* g = grandpa(n);

    if(p->left == n && g->right == p){
        printf("rotate right node [%d]\n", p->value);
        rotate_right(p);
        n = n->right;
    }
    else if(p->right == n && g->left == p){
        printf("rotate left node [%d]\n", p->value);
        rotate_left(p);
        n = n->left;
    }

    case5(n);
}

void case5(node* n){
    printf("case 5 on node [%d]\n", n->value);
    node* p = parent(n);
    node* g = grandpa(n);

    p->color = BLACK;
    g->color = RED;

    if(p->left == n && g->left == p){
        printf("rotate right node [%d]\n", g->value);
        rotate_right(g);
    }
    else if(p->right == n && g->right == p){
        printf("rotate left node [%d]\n", g->value);
        rotate_left(g);
    }
}

void rotate_left(node * n){
    printf("--------- rotate left node [%d] -----------\n", n->value);
    node *q = n->right;
    node *temp = q->left;

    printf("Q\n");
    pre_order(q);
    printf("TEMP\n");
    pre_order(temp);

    n->right = temp;

    if(n->right != nullptr)
        n->right->p = n;

    q->p = n->p;

    if(parent(n)){
        if(parent(n)->left == n)
            parent(n)->left = q;
        else
            parent(n)->right = q;
    }

    q->left = n;
    n->p = q;

    printf("-------- end rotate left -----------\n");
}

void rotate_right(node * n){
    printf("--------- rotate right node [%d] -----------\n", n->value);
    node *q = n->left;
    node *temp = q->right;

    printf("Q\n");
    pre_order(q);
    printf("TEMP\n");
    pre_order(temp);
/*
    q->right = n;
    n->left = temp;

    n = q;
*/
/*
    n->left = temp;
    q->right = n;

    if(parent(n)){
        if(parent(n)->left == n)
            parent(n)->left = q;
        else
            parent(n)->right = q;

        q->p = n->p;
        n->p = q;
    }
*/
    
    n->left = temp;

    if(n->left != nullptr)
        n->left->p = n;

    q->p = n->p;

    if(parent(n)){
        if(parent(n)->left == n)
            parent(n)->left = q;
        else
            parent(n)->right = q;
    }

    q->right = n;
    n->p = q;

    printf("new N: [%d, %s]\n", n->value, printc(n->color));
    printf("N parent: [%d, %s]\n", parent(n)->value, printc(parent(n)->color));

    printf("-------- end rotate right -----------\n");
}

int main(){
    vector<int> v { 41, 5, 90, 39, 79, 45, 81, 65, 59, 66 };     

    node* tree = nullptr;

    for(auto c : v){
        printf("Inserting %d\n", c);
        insert(c, &tree, nullptr);

        pre_order(tree);
        cout << endl;
    }

cout << endl << endl;
    pre_order(tree);


    return 0;
}
