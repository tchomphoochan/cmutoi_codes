///---LCA RMQ Version---///
#include <cstdio>
#include <vector>
#define SIZE 30000
using namespace std;

int log2(int a){
    return 32-__builtin_clz(a)-1;   /// Count Leading Zero
}
int V, idx[SIZE+5], RMQ[2*SIZE+5][20];
bool visited[SIZE+5];
vector<int> dfsOrder, lev, G[SIZE+5];

void dfs(int u, int level){
    visited[u] = true;
    dfsOrder.push_back(u);
    lev.push_back(level);
    if(idx[u] == -1)
        idx[u] = dfsOrder.size()-1;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!visited[v]){
            dfs(v, level+1);
            dfsOrder.push_back(u);
            lev.push_back(level);
        }
    }
    return;
}
void buildRMQ(){
    for(int i = 0; i < lev.size(); ++i)
        RMQ[i][0] = lev[i];
    int sizJ = log2(lev.size());
    for(int j = 1; j <= sizJ; ++j){
        for(int i = 0; i+(1<<j)-1 < lev.size(); ++i){
            RMQ[i][j] = min(RMQ[i][j-1], RMQ[i+(1<<(j-1))][j-1]);
        }
    }
}
int LCALevel(int x, int y){
    if(x > y)
        swap(x, y);
    int l = (y-x)+1;
    int log2L = log2(l);
    //printf("Q %d->%d (%d)\n", x, y, log2L);
    if((1<<log2L) == l)
        return RMQ[x][log2L];
    else{
        int x2 = y-(1<<log2L)+1;
        //printf("%d->%d && %d->%d\n", x, x+(1<<log2L)-1, x2, x2+(1<<log2L)-1);
        return min(RMQ[x][log2L], RMQ[x2][log2L]);
    }
}

int main(){
    int M;
    scanf("%d", &V);
    for(int i = 1; i < V; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        idx[i] = -1;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    idx[V] = -1;
    dfs(1, 0);
    buildRMQ();
    /*
    for(int i = 0; i < lev.size(); ++i){
        for(int j = 0; j < log2(lev.size()); ++j){
            if(i+(1<<j)-1 >= lev.size())
                break;
            printf("%d(%d->%d) ", RMQ[i][j], i, i+(1<<j)-1);
        }
        printf("\n");
    }
    printf("IDX->");
    for(int i = 1; i <= V; ++i){
        printf("%d ", idx[i]);
    }
    printf("\nOrder->");
    for(int i = 0; i <dfsOrder.size(); ++i){
        printf("%d ", dfsOrder[i]);
    }
    printf("\n");
    for(int i = 0; i < lev.size(); ++i)
        printf("%2d ", i);
    printf("\n");
    //printf("\nLevel->");
    for(int i = 0; i < lev.size(); ++i)
        printf("%2d ", lev[i]);
    //*/
    scanf("%d", &M);
    int cur = 1, sum = 0;
    for(int i = 0; i < M; ++i){
        int dest;
        scanf("%d", &dest);
        int levLCA = LCALevel(idx[cur], idx[dest]);
        sum+=lev[idx[cur]]+lev[idx[dest]]-2*levLCA;
        cur = dest;
    }
    printf("%d", sum);
    return 0;
}
/*
5
1 2
1 5
3 5
4 5
4
1
3
2
5

11
1 2
2 3
2 4
4 5
4 6
1 7
7 8
7 9
9 10
9 11
4
1
3
2
5
*/
///---LCA While Loop Version---///
/*
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

class NODE{
public:
    int prev, u, w;
    NODE(int prev, int u, int w){
        this->prev = prev;
        this->u = u;
        this->w = w;
    }
};
int V, lev[30005], parent[30005];
vector<int> G[30005];
int bfs(int st){
    queue<NODE> q;
    q.push(NODE(-1, st, 0));
    while(!q.empty()){
        int u = q.front().u, prev = q.front().prev, w = q.front().w;
        parent[u] = prev;
        lev[u] = w;
        q.pop();
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if(v == prev)
                continue;
            q.push(NODE(u, v, w+1));
        }
    }
}

int LCA(int a, int b){
    if(lev[a] < lev[b])
        swap(a, b);
    while(lev[a] > lev[b])
        a = parent[a];
    while(a != b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main(){
    int M;
    scanf("%d", &V);
    for(int i = 0; i < V-1; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bfs(1);
    scanf("%d", &M);
    int cur = 1, sum = 0;
    for(int i = 0; i < M; ++i){
        int dest;
        scanf("%d", &dest);
        sum+=lev[cur]+lev[dest]-2*lev[LCA(cur, dest)];
        cur = dest;
    }
    printf("%d", sum);
    return 0;
}
*/
