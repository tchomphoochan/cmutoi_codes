#include <cstdio>
#include <vector>
using namespace std;

class TreeNode{
public:
    vector<int> key;
    TreeNode *left, *right, *parent;
    TreeNode(int key){
        this->key.push_back(key);
        left = right = parent = NULL;
    }
};

class Tree{
public:
    TreeNode* root;
    void inOrder(TreeNode* current);
    Tree(){
        root = NULL;
    }
};

int order[100005], idx = 1;

void Tree::inOrder(TreeNode* current){
    if(current == NULL)
        return;
    inOrder(current->left);
    for(int i = 0; i < current->key.size(); ++i)
        order[current->key[i]] = idx;
    idx++;
    inOrder(current->right);
}

char inp[1000005];

int main(){
    Tree T;
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%s", inp);
        TreeNode *current = T.root, *prev = NULL;
        for(int j = 0; j < inp[j]; ++j){
            if(inp[j] == '*'){
                if(current != NULL){
                    current->key.push_back(i);
                    break;
                }
                TreeNode* newNode = new TreeNode(i);
                newNode->parent = prev;
                if(j && inp[j-1] == 'L')
                    prev->left = newNode;
                else if(j && inp[j-1] == 'R')
                    prev->right = newNode;
                else if(!j)
                    T.root = newNode;
            }
            else if(inp[j] == 'L'){
                prev = current;
                current = current->left;
            }
            else if(inp[j] == 'R'){
                prev = current;
                current = current->right;
            }
        }
    }
    T.inOrder(T.root);
    for(int i = 0; i < N; ++i)
        printf("%d\n", order[i]);
    return 0;
}
/*
7
*
R*
RR*
RRL*
RRLL*
L*
LR*
*/
