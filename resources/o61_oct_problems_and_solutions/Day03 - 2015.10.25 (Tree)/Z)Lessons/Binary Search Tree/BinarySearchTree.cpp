#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

class TreeNode{
public:
    int key;
    TreeNode *left, *right, *parent;
    TreeNode(int key){
        this->key = key;
        left = right = parent = NULL;
    }
};

class Tree{
public:
    TreeNode* root;
    TreeNode* INSERT(int key);
    TreeNode* FIND(int key, TreeNode* current);
    TreeNode* findMax(TreeNode* root);
    TreeNode* findMin(TreeNode* root);
    void DELETE(int key, TreeNode* root);
    void inOrder(TreeNode* current);
    void preOrder(TreeNode* current);
    void postOrder(TreeNode* current);
    Tree(){
        root = NULL;
    }
};

TreeNode* Tree::INSERT(int key){
    if(root == NULL){
        root = new TreeNode(key);
        return root;
    }
    TreeNode *current = root, *prev = NULL;
    while(current != NULL){
        prev = current;
        if(key < current->key)
            current = current->left;
        else
            current = current->right;
    }
    TreeNode* newNode = new TreeNode(key);
    newNode->parent = prev;
    if(key < prev->key)
        prev->left = newNode;
    else
        prev->right = newNode;
    return newNode;
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

void Tree::DELETE(int key, TreeNode* current){
    if(current == NULL)
        return;
    else if(key < current->key)
        DELETE(key, current->left);
    else if(key > current->key)
        DELETE(key, current->right);
    else if(current->left != NULL && current->right != NULL){
        TreeNode* rightMin = findMin(current->right);
        int tmp = rightMin->key;
        DELETE(rightMin->key, rightMin);
        current->key = tmp;
    }
    else{
        if(current->left != NULL){
            current->left->parent = current->parent;
            if(current->parent != NULL && current->key < current->parent->key)
                current->parent->left = current->left;
            else if(current->parent != NULL && current->key >= current->parent->key)
                current->parent->right = current->left;
            else
                root = current->left;
            delete current;
        }
        else if(current->right != NULL){
            current->right->parent = current->parent;
            if(current->parent != NULL && current->key < current->parent->key)
                current->parent->left = current->right;
            else if(current->parent != NULL && current->key >= current->parent->key)
                current->parent->right = current->right;
            else
                root = current->right;
            delete current;
        }
        else{
            if(current->parent != NULL && current->key < current->parent->key)
                current->parent->left = NULL;
            else if(current->parent != NULL && current->key >= current->parent->key)
                current->parent->right = NULL;
            else
                root = NULL;
            delete current;
        }
    }
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
int Height(TreeNode* N){
    if(N == NULL)
        return 0;
    return max(Height(N->left), Height(N->right))+1;
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
    for(int i = 1; i <= 50; ++i)
        T.INSERT(rand()%20);
    T.inOrder(T.root);
    TreeNode *Max = T.findMax(T.root), *Min = T.findMin(T.root);
    printf("\n--------------------------\nMAX: %d\nMIN: %d\n--------------------------\n", Max->key, Min->key);
    printf("ROOT: %d %d\n", T.root->key, Height(T.root));
    for(int i = 1; i <= 10; ++i){
        int f = rand()%20;
        printf("Find: %3d\t", f);
        TreeNode* F = T.FIND(f, T.root);
        if(F == NULL)
            printf("Not Found\n");
        else
            printf("Found\n");
    }
    //*
    while(T.root != NULL){
        int d = rand()%20;
        printf("DELETE: %3d!!\n", d);
        T.DELETE(d, T.root);
        T.inOrder(T.root);
        printf("\n");
    }
    //*/
    return 0;
}
