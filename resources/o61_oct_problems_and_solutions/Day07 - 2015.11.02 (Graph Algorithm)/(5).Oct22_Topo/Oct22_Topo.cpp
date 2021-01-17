///-------DFS Version-------///
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
// 0-White 1-Grey 2-Black
// If Grey Node visited other Grey Node, then we have a cycle

int V, E, visited[100005];
vector<int> G[100005], topoOrder;

bool topo(int u){
    visited[u] = 1;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(visited[v] == 0){
            if(topo(v))
                return 1;
        }
        else if(visited[v] == 1)
            return 1;
    }
    visited[u] = 2;
    topoOrder.push_back(u);
    return 0;
}

int main(){
    scanf("%d%d", &V, &E);
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
    }
    bool cycle = false;
    for(int i = 1; i <= V && !cycle; ++i){
        if(!visited[i])
            cycle = topo(i);
    }
    if(!cycle)
        for(int i = V-1; i >= 0; --i)
            printf("%d\n", topoOrder[i]);
    else
        printf("no");
    return 0;
}

///-------BFS Version-------///
/*
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int V, E, inDeg[100005];
vector<int> G[100005], ans;
queue<int> q;

void bfsTopo(){
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if(--inDeg[v] == 0)
                q.push(v);
        }
    }
}

int main(){
    scanf("%d%d", &V, &E);
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        inDeg[y]++;
    }
    for(int i = 1; i <= V; ++i){
        if(inDeg[i] == 0)
            q.push(i);
    }
    bfsTopo();
    if(ans.size() == V)
        for(int i = 0; i < V; ++i)
            printf("%d\n", ans[i]);
    else
        printf("no");
    return 0;
}
*/
