#include <cstdio>

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
    Tree(){
        root = NULL;
    }
};

TreeNode* Tree::INSERT(int key){
    if(root == NULL){
        printf("*");
        root = new TreeNode(key);
        return root;
    }
    TreeNode *current = root, *prev = NULL;
    while(current != NULL){
        prev = current;
        if(key < current->key){
            current = current->left;
            printf("L");
        }
        else{
            current = current->right;
            printf("R");
        }
    }
    printf("*");
    TreeNode* newNode = new TreeNode(key);
    newNode->parent = prev;
    if(key < prev->key)
        prev->left = newNode;
    else
        prev->right = newNode;
    return newNode;
}

int main(){
    Tree T;
    int N;
    scanf("%d", &N);
    while(N--){
        int x;
        scanf("%d", &x);
        T.INSERT(x);
        printf("\n");
    }
    return 0;
}
/*
7
1
2
5
4
3
-2
-1
*/
