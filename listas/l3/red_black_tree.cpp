#include <bits/stdc++.h>
#define BLACK 0
#define RED 1

using namespace std;

typedef struct _node {
    int value, color;
    struct _node *parent, *left, *right;
} node;

int count_rotations = 0;

node* grandpa(node* n);
node* uncle(node* n);
const char* print_color(int c);
void print_node(string label, node* n);

class RBTree {
    public:
        node *root;

        RBTree() {
            root = nullptr;
        }

        void insert(int val);
        void case1(node* n);
        void case2(node* n);
        void case3(node* n);
        void case4(node* n);
        void case5(node* n);
        void rotate_left(node* n);
        void rotate_right(node* n);
        void pre_order(node *n, int step = 0);
};

// Main function
int main(){
//    vector<int> v { 41, 5, 90, 39, 79, 45, 81, 65, 59, 66 };
    vector<int> v { 10,7, 6, 8, 12, 11, 13 };

    count_rotations = 0;
    RBTree* tree = new RBTree();

    for(auto c : v){
        printf("--------------------------------------------------\n");
        printf("Inserting [%d]\n", c);
        tree->insert(c);

        printf("--------------------------------------------------\n");
        printf("Current tree\n");
        tree->pre_order(tree->root);

        printf("--------------------------------------------------\n");
        printf("Finish inserting %d\n", c);
        printf("--------------------------------------------------\n");
        cout << endl;
    }

    printf("Complete tree\n");
    cout << endl;
    tree->pre_order(tree->root);

    printf("\nNumber of rotations: %d\n", count_rotations);

    return 0;
}

// Auxiliar methods
node* grandpa(node* n){
    if(n && n->parent)
        return n->parent->parent;
    return nullptr;
}

node* uncle(node* n){
    node *g = grandpa(n);

    if(g == nullptr)
        return nullptr;
    if(g->left == n->parent)
        return g->right;
    return g->left;
}

const char* print_color(int c){
    return c ? "RED" : "BLACK";
}

void print_node(string label, node* n){
    printf("Node [%s]: ", label.c_str());
    if(n)
        printf("[%d, %s]\n", n->value, print_color(n->color));
    else
        printf("null\n");
}

// RBTree methods
void RBTree::insert(int val){
    node* n = (node*) malloc(sizeof(node));
    n->value = val;
    n->color = RED;
    n->left = nullptr;
    n->right = nullptr;


    if(root == nullptr){
        root = n;
        n->parent = nullptr;
    }
    else{
        node* aux = root, *q = nullptr;

        while(aux != nullptr){
            q = aux;
            if(val > aux->value)
                aux = aux->right;
            else
                aux = aux->left;
        }

        n->parent = q;
        if(q->value > n->value)
            q->left = n;
        else
            q->right = n;
    }

    case1(n);
}

void RBTree::case1(node* n){
    if(root == n){
        n->color = BLACK;
        return;
    }
    else{
        case2(n);
    }
}

void RBTree::case2(node* n){
    if(n->parent->color == BLACK){
        return;
    }
    else{
        case3(n);
    }
}

void RBTree::case3(node* n){
    node* u = uncle(n);
    node* g = grandpa(n);

    if(u && u->color == RED){
        n->parent->color = BLACK;
        u->color = BLACK;
        g->color = RED;

        case1(g);
    }
    else{
        case4(n);
    }
}

void RBTree::case4(node* n){
    node *g = grandpa(n);

    if(g->left == n->parent && n->parent->right == n){
        rotate_left(n->parent);
        n = n->left;
    }
    else if(g->right == n->parent && n->parent->left == n){
        rotate_right(n->parent);
        n = n->right;
    }

    case5(n);
}

void RBTree::case5(node* n){
    node *g = grandpa(n);

    n->parent->color = BLACK;
    g->color = RED;

    if(g->right == n->parent && n->parent->right == n){
        rotate_left(g);
    }
    else if(g->left == n->parent && n->parent->left == n){
        rotate_right(g);
    }
}

void RBTree::rotate_right(node* n){
    count_rotations++;
    // check if n is leaf
    if(n->left == nullptr)
        return;

    node* q = n->left;
    node* temp = q->right;

    n->left = temp;
    if(temp){
        temp->parent = n;
    }

    if(n->parent){
        q->parent = n->parent;

        if(n->parent->left == n)
            n->parent->left = q;
        else
            n->parent->right = q;
    }
    else{
        root = q;
    }

    q->right = n;
    n->parent = q;
}

void RBTree::rotate_left(node* n){
    count_rotations++;
    // check if n is leaf
    if(n->right == nullptr)
        return;

    node* q = n->right;
    node* temp = q->left;

    n->right = temp;
    if(temp){
        temp->parent = n;
    }

    if(n->parent){
        q->parent = n->parent;

        if(n->parent->left == n)
            n->parent->left = q;
        else
            n->parent->right = q;
    }
    else{
        root = q;
    }

    q->left = n;
    n->parent = q;
}

void RBTree::pre_order(node *n, int step){
    for(int i=0;i<step;i++) printf(" ");
    if(n == nullptr){
        printf("null\n");
        return;
    }

    printf("[%d, %s]\n", n->value, print_color(n->color));

    pre_order(n->left, step + 4);
    pre_order(n->right, step + 4);
}
