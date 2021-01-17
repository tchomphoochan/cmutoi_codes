#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

class TreeNode{
public:
    int key, height;
    TreeNode *left, *right, *parent;
    TreeNode(int key){
        this->key = key;
        left = right = parent = NULL;
        height = 1;
    }
};

class Tree{
public:
    TreeNode* root;
    TreeNode* INSERT(int key, TreeNode* current);
    TreeNode* FIND(int key, TreeNode* current);
    TreeNode* findMax(TreeNode* root);
    TreeNode* findMin(TreeNode* root);
    TreeNode* rightRotate(TreeNode* x);
    TreeNode* leftRotate(TreeNode* x);
    int Height(TreeNode* current);
    int Balance(TreeNode* current);
    void inOrder(TreeNode* current);
    void preOrder(TreeNode* current);
    void postOrder(TreeNode* current);
    Tree(){
        root = NULL;
    }
};

int Tree::Height(TreeNode* current){
    if(current == NULL)
        return 0;
    else
        return current->height;
}
int Tree::Balance(TreeNode* current){
    if(current == NULL)
        return 0;
    else
        return Height(current->left)-Height(current->right);
}
TreeNode* Tree::rightRotate(TreeNode* x){
    TreeNode* y = x->left, *T3 = y->right;
    y->parent = x->parent;
    x->parent = y;
    if(T3 != NULL)
        T3->parent = x;
    x->left = T3;
    y->right = x;
    x->height = max(Height(x->left), Height(x->right))+1;
    y->height = max(Height(y->left), Height(y->right))+1;
    return y;
}
TreeNode* Tree::leftRotate(TreeNode* x){
    TreeNode* y = x->right, *T2 = y->left;
    y->parent = x->parent;
    x->parent = y;
    if(T2 != NULL)
        T2->parent = x;
    x->right = T2;
    y->left = x;
    x->height = max(Height(x->left), Height(x->right))+1;
    y->height = max(Height(y->left), Height(y->right))+1;
    return y;
}

TreeNode* Tree::INSERT(int key, TreeNode* current){
    if(current == NULL){
        TreeNode *newNode = new TreeNode(key);
        newNode->parent = current;
        return newNode;
    }
    if(key < current->key)
        current->left = INSERT(key, current->left);
    else
        current->right = INSERT(key, current->right);
    current->height = max(Height(current->left), Height(current->right)) + 1;
    int balance = Balance(current);
    // Left Left Case
    if(balance > 1 && key < current->left->key)
        return rightRotate(current);
    // Right Right Case
    else if(balance < -1 && key >= current->right->key)
        return leftRotate(current);
    // Left Right Case
    else if(balance > 1 && key >= current->left->key){
        current->left = leftRotate(current->left);
        return rightRotate(current);
    }
    // Right Left Case
    else if(balance < -1 && key < current->right->key){
        current->right = rightRotate(current->right);
        return leftRotate(current);
    }
    else
        return current;
}

TreeNode* Tree::FIND(int key, TreeNode* root){
    if(root == NULL)
        return NULL;
    else{
        TreeNode* current = root;
        while(current != NULL){
            if(key == current->key)
                return current;
            else if(key < current->key)
                current = current->left;
            else if(key > current->key)
                current = current->right;
        }
    }
    return NULL;
}

TreeNode* Tree::findMax(TreeNode* root){
    if(root == NULL)
        return NULL;
    else{
        TreeNode* current = root;
        while(current->right != NULL)
            current = current->right;
        return current;
    }
}

TreeNode* Tree::findMin(TreeNode* root){
    if(root == NULL)
        return NULL;
    else{
        TreeNode* current = root;
        while(current->left != NULL)
            current = current->left;
        return current;
    }
}

void Tree::inOrder(TreeNode* current){
    if(current == NULL)
        return;
    else{
        inOrder(current->left);
        printf("%d ", current->key);
        inOrder(current->right);
    }
}

void Tree::preOrder(TreeNode* current){
    if(current == NULL)
        return;
    else{
        printf("%d ", current->key);
        inOrder(current->left);
        inOrder(current->right);
    }
}

void Tree::postOrder(TreeNode* current){
    if(current == NULL)
        return;
    else{
        inOrder(current->left);
        inOrder(current->right);
        printf("%d ", current->key);
    }
}

int main(){
    srand(time(NULL));
    Tree T;
    /*
    T.INSERT(22);
    T.INSERT(0);
    T.INSERT(0);
    T.INSERT(42);
    T.DELETE(22, T.root);
    T.inOrder(T.root);
    printf("\n");
    T.DELETE(0, T.root);
    T.inOrder(T.root);
    printf("\n");
    T.DELETE(42, T.root);
    T.inOrder(T.root);
    printf("\n");
    */
    //*
    for(int i = 1; i <= 100; ++i){
        int x = rand()%500;
        printf("%d ", x);
        T.root = T.INSERT(x, T.root);
    }
    printf("\n\n");
    T.inOrder(T.root);
    TreeNode *Max = T.findMax(T.root), *Min = T.findMin(T.root);
    printf("\n--------------------------\nMAX: %d\nMIN: %d\n--------------------------\n", Max->key, Min->key);
    printf("ROOT: %d H:%d\n\n", T.root->key, T.root->height);
    for(int i = 1; i <= 10; ++i){
        int f = rand()%500;
        printf("Find: %3d\t", f);
        TreeNode* F = T.FIND(f, T.root);
        if(F == NULL)
            printf("Not Found\n");
        else
            printf("Found\n");
    }
    //*/
    return 0;
}

