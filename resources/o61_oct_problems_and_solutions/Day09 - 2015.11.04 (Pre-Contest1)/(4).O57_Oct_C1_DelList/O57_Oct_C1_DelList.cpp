#include <cstdio>
#include <map>
#include <vector>
#define mp make_pair
#define pb push_back
using namespace std;

class ListNode{
public:
    int val;
    ListNode *l, *r;
    ListNode(){
        l = r = NULL;
    }
    ListNode(int val){
        this->val = val;
        l = r = NULL;
    }
};
int H[100005];
ListNode *head[100005], *tail[100005];
map<int, vector<pair<int, ListNode*> > > hah;
int findH(int a){
    if(H[a] == a)
        return a;
    return H[a] = findH(H[a]);
}
void INSERT(int group, int x){
    ListNode *newNode = new ListNode(x);
    hah[x].pb(mp(group, newNode));
    if(head[group] == NULL){
        head[group] = newNode;
        tail[group] = newNode;
    }
    else{
        tail[group]->r = newNode;
        newNode->l = tail[group];
        tail[group] = newNode;
    }
}
void MERGE(int parent, int child){
    if(head[child] != NULL)
        head[child]->l = tail[parent];
    else
        return;
    if(tail[parent] != NULL){
        tail[parent]->r = head[child];
        tail[parent] = tail[child];
    }
    else{
        head[parent] = head[child];
        tail[parent] = tail[child];
    }
    head[child] = NULL;
    tail[child] = NULL;
}
void DELETE(int group, int del){
    map<int, vector<pair<int, ListNode*> > >::iterator it = hah.find(del);
    if(it == hah.end())
        return;
    for(int i = 0; i < it->second.size(); ++i){
        if(findH(it->second[i].first) != group)
            continue;
        ListNode *now = it->second[i].second, *left = now->l, *right = now->r;
        if(right != NULL)
            right->l = left;
        if(left != NULL)
            left->r = right;
        if(now == head[group])
            head[group] = right;
        if(now == tail[group])
            tail[group] = left;
        delete now;
        it->second[i].first = 0;
    }
}

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; ++i){
        H[i] = i;
        int n;
        scanf("%d", &n);
        for(int j = 0; j < n; ++j){
            int x;
            scanf("%d", &x);
            INSERT(i, x);
        }
    }
    for(int i = 1; i <= M; ++i){
        int opr;
        scanf("%d", &opr);
        if(opr == 1){
            int g, del;
            scanf("%d%d", &g, &del);
            DELETE(g, del);
        }
        else if(opr == 2){
            int x, y;
            scanf("%d%d", &x, &y);
            int hX = findH(x), hY = findH(y);
            H[hY] = H[hX];
            MERGE(x, y);
        }
        /*
        for(int i = 1; i <= N; ++i){
            ListNode *trav = head[i];
            printf("->");
            while(trav != NULL){
                printf("%d ", trav->val);
                trav = trav->r;
            }
            printf("\n");
        }
        //*/
    }
    for(int i = 1; i <= N; ++i){
        ListNode *trav = head[i];
        while(trav != NULL){
            printf("%d\n", trav->val);
            trav = trav->r;
        }
    }
    return 0;
}
/*
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *l, *r;
    ListNode(){
        l = r = NULL;
    }
    ListNode(int val){
        this->val = val;
        l = r = NULL;
    }
};
ListNode *head[100005], *tail[100005];
map<int, vector<ListNode*> > hah[100005];
void INSERT(int group, int x){
    ListNode *newNode = new ListNode(x);
    hah[group][x].push_back(newNode);
    if(head[group] == NULL){
        head[group] = newNode;
        tail[group] = newNode;
    }
    else{
        tail[group]->r = newNode;
        newNode->l = tail[group];
        tail[group] = newNode;
    }
}
void MERGE(int parent, int child){
    if(head[child] != NULL)
        head[child]->l = tail[parent];
    else
        return;
    if(tail[parent] != NULL){
        tail[parent]->r = head[child];
        tail[parent] = tail[child];
    }
    else{
        head[parent] = head[child];
        tail[parent] = tail[child];
    }
    head[child] = NULL;
    tail[child] = NULL;
    for(map<int, vector<ListNode*> >::iterator it = hah[child].begin(); it != hah[child].end(); ++it)
        hah[parent][it->first].insert(hah[parent][it->first].end(), it->second.begin(), it->second.end());
    hah[child].clear();
}
void DELETE(int group, int del){
    map<int, vector<ListNode*> >::iterator it = hah[group].find(del);
    if(it == hah[group].end())
        return;
    for(int i = 0; i < it->second.size(); ++i){
        ListNode *now = it->second[i], *left = now->l, *right = now->r;
        if(right != NULL)
            right->l = left;
        if(left != NULL)
            left->r = right;
        if(now == head[group])
            head[group] = right;
        if(now == tail[group])
            tail[group] = left;
        delete now;
    }
    hah[group].erase(it);
}

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; ++i){
        int n;
        scanf("%d", &n);
        for(int j = 0; j < n; ++j){
            int x;
            scanf("%d", &x);
            INSERT(i, x);
        }
    }
    for(int i = 1; i <= M; ++i){
        int opr;
        scanf("%d", &opr);
        if(opr == 1){
            int g, del;
            scanf("%d%d", &g, &del);
            DELETE(g, del);
        }
        else if(opr == 2){
            int x, y;
            scanf("%d%d", &x, &y);
            MERGE(x, y);
        }
        /*
        for(int i = 1; i <= N; ++i){
            ListNode *trav = head[i];
            printf("->");
            while(trav != NULL){
                printf("%d ", trav->val);
                trav = trav->r;
            }
            printf("\n");
        }
        //
    }
    for(int i = 1; i <= N; ++i){
        ListNode *trav = head[i];
        while(trav != NULL){
            printf("%d\n", trav->val);
            trav = trav->r;
        }
    }
    return 0;
}
*/
/*
3 4
3
1 2 1
3
10 20 1
4
1 2 3 4
1 1 1
2 1 3
1 1 1
2 2 1

3 5
3
1 2 1
3
10 20 1
4
1 2 3 4
2 1 3
2 2 1
1 2 1
1 2 2
2 1 2
*/
