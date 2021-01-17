#include <cstdio>

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
    TreeNode* rightRotate(TreeNode* x);
    TreeNode* leftRotate(TreeNode* x);
    int Height(TreeNode* current);
    int Balance(TreeNode* current);
    Tree(){
        root = NULL;
    }
};

int max(int a, int b){
    return a>b? a:b;
}

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
    TreeNode* y = x->left;
    x->left = y->right;
    y->right = x;
    x->height = max(Height(x->left), Height(x->right))+1;
    y->height = max(Height(y->left), Height(y->right))+1;
    return y;
}
TreeNode* Tree::leftRotate(TreeNode* x){
    TreeNode* y = x->right;
    x->right = y->left;
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
    else if(key > current->key)
        current->right = INSERT(key, current->right);
    current->height = max(Height(current->left), Height(current->right)) + 1;
    int balance = Balance(current);
    // Left Left Case
    if(balance > 1 && key < current->left->key)
        return rightRotate(current);
    // Right Right Case
    else if(balance < -1 && key > current->right->key)
        return leftRotate(current);
    // Left Right Case
    else if(balance > 1 && key > current->left->key){
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

int main(){
    Tree T;
    int N, Q, x;
    scanf("%d%d", &N, &Q);
    while(N--){
        scanf("%d", &x);
        T.root = T.INSERT(x, T.root);
    }
    //printf("ROOT: %d %d\n", T.root->key, T.root->height);
    while(Q--){
        scanf("%d", &x);
        if(T.FIND(x, T.root) != NULL)
            printf("y\n");
        else
            printf("n\n");
    }
    return 0;
}
/*
5 5
10
2
7
20
25
2
10
13
15
20
*/
