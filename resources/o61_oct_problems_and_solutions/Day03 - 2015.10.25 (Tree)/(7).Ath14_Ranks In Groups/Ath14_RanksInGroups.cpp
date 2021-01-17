#include <cstdio>

class TreeNode{
public:
    int key, height, childLeft, childRight;
    TreeNode *left, *right, *parent;
    TreeNode(int key){
        this->key = key;
        left = right = parent = NULL;
        height = 1;
        childLeft = childRight = 0;
    }
};

class Tree{
public:
    TreeNode* root;
    TreeNode* INSERT(int key, TreeNode* current, TreeNode* prev);
    TreeNode* FIND(int key, TreeNode* current);
    TreeNode* rightRotate(TreeNode* x);
    TreeNode* leftRotate(TreeNode* x);
    int Height(TreeNode* current);
    int Balance(TreeNode* current);
    void inOrder(TreeNode* current);
    void cntMoreThan(int key, TreeNode* current);
    void postOrderMerge(TreeNode* current, int to);
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
    TreeNode *y = x->left, *T3 = y->right;

    x->childLeft = y->childRight;
    y->childRight+=x->childRight+1;

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
    TreeNode *y = x->right, *T2 = y->left;

    x->childRight = y->childLeft;
    y->childLeft+=x->childLeft+1;

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

TreeNode* Tree::INSERT(int key, TreeNode* current, TreeNode* prev){
    if(current == NULL){
        TreeNode *newNode = new TreeNode(key);
        newNode->parent = prev;
        return newNode;
    }
    if(key < current->key)
        current->left = INSERT(key, current->left, current);
    else if(key > current->key)
        current->right = INSERT(key, current->right, current);
    current->height = max(Height(current->left), Height(current->right)) + 1;
    if(current->left != NULL)
        current->childLeft = current->left->childLeft + current->left->childRight + 1;
    if(current->right != NULL)
        current->childRight = current->right->childRight + current->right->childLeft + 1;
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

int group[100005], N, idx, cnt;
Tree T[100005];
int findG(int a){
    if(group[a] == a)
        return a;
    return group[a] = findG(group[a]);
}

void Tree::inOrder(TreeNode* current){
    if(current == NULL)
        return;
    inOrder(current->left);
    printf("(%d,%d-%d) ", current->key, current->childLeft, current->childRight);
    inOrder(current->right);
}
void Tree::postOrderMerge(TreeNode* current, int to){
    if(current == NULL)
        return;
    postOrderMerge(current->left, to);
    postOrderMerge(current->right, to);
    T[to].root = T[to].INSERT(current->key, T[to].root, NULL);
    delete current;
}
void Tree::cntMoreThan(int key, TreeNode* current){
    if(current == NULL)
        return;
    //printf("CNT(%d, %d)\n", current->key, current->childRight);
    if(current->key >= key)
        cnt+=current->childRight+1;
    if(current->parent == NULL)
        return;
    cntMoreThan(key, current->parent);
}

int main(){
    int L;
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        scanf("%d%d", &N, &L);
        for(int i = 1; i <= N; ++i){
            T[i].root = NULL;
            T[i].root = T[i].INSERT(i, T[i].root, NULL);
            group[i] = i;
        }
        for(int i = 0; i < L; ++i){
            /*
            for(int k = 1; k <= N; ++k){
                printf("---Tree %d---\n", k);
                T[k].inOrder(T[k].root);
                printf("\n");
            }
            //*/
            int opr, x, y, j;
            scanf("%d", &opr);
            if(opr == 1){
                scanf("%d%d", &x, &y);
                group[y] = x;
                T[y].postOrderMerge(T[y].root, x);
                T[y].root = NULL;
            }
            else if(opr == 2){
                scanf("%d", &j);
                int idxT = findG(j);
                TreeNode* trav = T[idxT].FIND(j, T[idxT].root);
                cnt = 0;
                T[idxT].cntMoreThan(trav->key, trav);
                printf("%d\n", cnt);
            }
        }
    }
    return 0;
}
/*
2
3 5
2 2
1 2 3
2 2
1 1 2
2 2
5 5
1 1 2
1 1 3
1 1 4
1 1 5
2 1

2
3 5
2 2
1 2 3
2 2
1 1 2
2 2
4 4
1 1 2
1 1 3
1 1 4
2 2

1
4 7
2 1
1 3 4
2 3
1 4 2
2 3
1 1 2
2 2
*/
