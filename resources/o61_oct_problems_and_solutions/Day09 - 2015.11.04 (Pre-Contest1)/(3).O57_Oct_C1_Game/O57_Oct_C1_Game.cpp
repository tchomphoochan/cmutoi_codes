#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V, E, Rank[5005], idx, componentNum[5005], sizeInCom[5005], comRank[5005], inDeg[5005];
bool topoVisited[5005], topoVisited2[5005], dfsVisited[5005];
vector<int> G[5005], Gt[5005], GCom[5005], topoOrder;
vector<pair<int, int> > edge;
queue<pair<int, int> > q;
void topo(int u){
    topoVisited[u] = true;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!topoVisited[v])
            topo(v);
    }
    topoOrder.push_back(u);
}
void bfsTopo(){
    while(!q.empty()){
        int u = q.front().first, state = q.front().second;
        q.pop();
        Rank[state]+=sizeInCom[u];
        for(int i = 0; i < GCom[u].size(); ++i){
            int v = GCom[u][i];
            if(--inDeg[v] == 0)
                q.push(make_pair(v, state+1));
        }
    }
}
void dfs(int u){
    dfsVisited[u] = true;
    for(int i = 0; i < Gt[u].size(); ++i){
        int v = Gt[u][i];
        if(!dfsVisited[v])
            dfs(v);
    }
    componentNum[u] = idx;
    sizeInCom[idx]++;
}

int main(){
    scanf("%d%d", &V, &E);
    edge.resize(E);
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        Gt[y].push_back(x);
        edge[i] = make_pair(x, y);
    }
    for(int i = 0; i < V; ++i){
        if(!topoVisited[i])
            topo(i);
    }
    idx = 0;
    for(int i = topoOrder.size()-1; i >= 0; --i){
        //printf("%d ", topoOrder[i]);
        if(!dfsVisited[topoOrder[i]]){
            dfs(topoOrder[i]);
            idx++;
        }
    }
    for(int i = 0; i < E; ++i){
        int x = componentNum[edge[i].first], y = componentNum[edge[i].second];
        if(x != y){
            GCom[x].push_back(y);
            inDeg[y]++;
            //printf("%d->%d\n", x, y);
        }
    }
    for(int i = 0; i < idx; ++i){
        if(inDeg[i] == 0)
            q.push(make_pair(i, 0));
    }
    bfsTopo();
    for(int i = 0; Rank[i] != 0; ++i)
        printf("%d ", Rank[i]);
    return 0;
}
/*
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, Rank[5005], idx, componentNum[5005], sizeInCom[5005], comRank[5005];
bool topoVisited[5005], topoVisited2[5005], dfsVisited[5005], dfsVisited2[5005];
vector<int> G[5005], Gt[5005], GCom[5005], topoOrder, topoOrder2;
vector<pair<int, int> > edge;
void topo(int u){
    topoVisited[u] = true;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!topoVisited[v])
            topo(v);
    }
    topoOrder.push_back(u);
}
void topo2(int u){
    topoVisited2[u] = true;
    for(int i = 0; i < GCom[u].size(); ++i){
        int v = GCom[u][i];
        if(!topoVisited2[v])
            topo2(v);
    }
    topoOrder2.push_back(u);
}
void dfs(int u){
    dfsVisited[u] = true;
    for(int i = 0; i < Gt[u].size(); ++i){
        int v = Gt[u][i];
        if(!dfsVisited[v])
            dfs(v);
    }
    componentNum[u] = idx;
    sizeInCom[idx]++;
}
void dfs2(int u, int state){
    dfsVisited2[u] = true;
    for(int i = 0; i < GCom[u].size(); ++i){
        int v = GCom[u][i];
        if(!dfsVisited2[v])
            dfs2(v, state+1);
    }
    dfsVisited2[u] = false;
    comRank[u] = max(comRank[u], state);
}

int main(){
    scanf("%d%d", &V, &E);
    edge.resize(E);
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        Gt[y].push_back(x);
        edge[i] = make_pair(x, y);
    }
    for(int i = 0; i < V; ++i){
        if(!topoVisited[i])
            topo(i);
    }
    idx = 0;
    for(int i = topoOrder.size()-1; i >= 0; --i){
        //printf("%d ", topoOrder[i]);
        if(!dfsVisited[topoOrder[i]]){
            dfs(topoOrder[i]);
            idx++;
        }
    }
    //*
    for(int i = 0; i < V; ++i)
        printf("(%d): %d\n", i, componentNum[i]);
    //
    for(int i = 0; i < E; ++i){
        int x = componentNum[edge[i].first], y = componentNum[edge[i].second];
        if(x != y){
            GCom[x].push_back(y);
            //printf("%d->%d\n", x, y);
        }
    }
    for(int i = 0; i < idx; ++i){
        if(!topoVisited2[i])
            topo2(i);
        comRank[i] = -1;
    }
    for(int i = topoOrder2.size()-1; i >= 0; --i){
        //printf("%d ", topoOrder2[i]);
        //if(!dfsVisited2[topoOrder2[i]])
        if(comRank[topoOrder2[i]] == -1)
            dfs2(topoOrder2[i], 0);
    }
    for(int i = 0; i < idx; ++i)
        Rank[comRank[i]]+=sizeInCom[i];
    for(int i = 0; Rank[i] != 0; ++i)
        printf("%d ", Rank[i]);
    return 0;
}
*/
/*
4 3
2 1
2 0
1 3

4 5
0 1
1 2
2 0
2 3
1 3

5 4
3 4
4 1
0 1
1 2

8 7
0 1
1 2
2 3
3 4
4 5
5 6
7 3

11 12
0 1
1 2
2 3
3 4
4 5
5 6
7 3
0 8
8 9
9 10
10 9
10 0
*/
