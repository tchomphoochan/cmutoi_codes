#include <cstdio>
#include <vector>
using namespace std;

class TreeNode{
public:
    pair<int, int> key;
    TreeNode *left, *right, *parent;
    TreeNode(pair<int, int> key){
        this->key = key;
        left = right = parent = NULL;
    }
};

class Tree{
public:
    TreeNode* root;
    TreeNode* INSERT(pair<int, int> key);
    TreeNode* FIND(pair<int, int> key, TreeNode* current);
    TreeNode* findMax(TreeNode* root);
    TreeNode* findMin(TreeNode* root);
    void DELETE(pair<int, int> key, TreeNode* root);
    void inOrder(TreeNode* current);
    Tree(){
        root = NULL;
    }
};

TreeNode* Tree::INSERT(pair<int, int> key){
    if(root == NULL){
        root = new TreeNode(key);
        return root;
    }
    TreeNode *current = root, *prev = NULL;
    while(current != NULL){
        prev = current;
        if(key.first < current->key.first)
            current = current->left;
        else
            current = current->right;
    }
    TreeNode* newNode = new TreeNode(key);
    newNode->parent = prev;
    if(key.first < prev->key.first)
        prev->left = newNode;
    else
        prev->right = newNode;
    return newNode;
}

TreeNode* Tree::FIND(pair<int, int> key, TreeNode* root){
    if(root == NULL)
        return NULL;
    else{
        TreeNode* current = root;
        while(current != NULL){
            if(key.first == current->key.first && key.second == current->key.second)
                return current;
            else if(key.first < current->key.first)
                current = current->left;
            else if(key.first > current->key.first)
                current = current->right;
        }
    }
    return NULL;
}

void Tree::DELETE(pair<int, int> key, TreeNode* current){
    if(current == NULL)
        return;
    else if(key.first < current->key.first)
        DELETE(key, current->left);
    else if(key.first > current->key.first)
        DELETE(key, current->right);
    else if(key == current->key && current->left != NULL && current->right != NULL){
        TreeNode* rightMin = findMin(current->right);
        pair<int, int> tmp = rightMin->key;
        DELETE(rightMin->key, rightMin);
        current->key = tmp;
    }
    else if(key == current->key){
        if(current->left != NULL){
            current->left->parent = current->parent;
            if(current->parent != NULL && current->key.first < current->parent->key.first)
                current->parent->left = current->left;
            else if(current->parent != NULL && current->key.first >= current->parent->key.first)
                current->parent->right = current->left;
            else
                root = current->left;
        }
        else if(current->right != NULL){
            current->right->parent = current->parent;
            if(current->parent != NULL && current->key.first < current->parent->key.first)
                current->parent->left = current->right;
            else if(current->parent != NULL && current->key.first >= current->parent->key.first)
                current->parent->right = current->right;
            else
                root = current->right;
        }
        else{
            if(current->parent != NULL && current->key.first < current->parent->key.first)
                current->parent->left = NULL;
            else if(current->parent != NULL && current->key.first >= current->parent->key.first)
                current->parent->right = NULL;
            else
                root = NULL;
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
    inOrder(current->left);
    printf("(%d, %d) ", current->key.first, current->key.second);
    inOrder(current->right);
}

vector<TreeNode*> time[200005];
vector<pair<TreeNode*, int> > change[200005];

int main(){
    Tree T;
    int N, M, opr, type, w, v, t, x;
    scanf("%d%d", &N, &M);
    N+=M;
    for(int i = 1; i <= N; ++i){
        scanf("%d", &opr);
        for(int j = 0; j < time[i].size(); ++j)
            T.DELETE(time[i][j]->key, time[i][j]);
        for(int j = 0; j < change[i].size(); ++j){
            pair<int, int> tmp = change[i][j].first->key;
            if(T.FIND(tmp, T.root) != NULL){
                T.DELETE(tmp, change[i][j].first);
                T.INSERT(make_pair(change[i][j].second, tmp.second));
            }
        }
        if(opr == 1){
            scanf("%d", &type);
            if(type == 1){
                scanf("%d%d", &w, &v);
                TreeNode* newNode =  T.INSERT(make_pair(w, v));
            }
            else if(type == 2){
                scanf("%d%d", &w, &v);
                scanf("%d", &t);
                if(t <= 200000){
                    if(t != i){
                        TreeNode* newNode =  T.INSERT(make_pair(w, v));
                        time[t].push_back(newNode);
                    }
                }
            }
            else if(type == 3){
                scanf("%d%d", &w, &v);
                scanf("%d%d", &t, &x);
                if(t <= 200000){
                    if(t == i)
                        TreeNode* newNode =  T.INSERT(make_pair(x, v));
                    else{
                        TreeNode* newNode =  T.INSERT(make_pair(w, v));
                        change[t].push_back(make_pair(newNode, x));
                    }
                }
            }
        }
        else if(opr == 2){
            TreeNode* minW = T.findMin(T.root);
            if(minW == NULL)
                printf("0\n");
            else{
                printf("%d\n", minW->key.second);
                T.DELETE(minW->key, minW);
            }
        }
        /*
        printf("TIME %d: ", i);
        T.inOrder(T.root);
        printf("\n\n");
        //*/
    }
    return 0;
}
/*
5 4
1 1 10 20
1 2 30 10 3
2
2
1 3 40 20 7 5
1 1 30 30
1 2 25 50 7
2
2
*/
