#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int V, E, color[100005];
vector<int> G[100005];
queue<int> q;
void RESET(){
    for(int i = 1; i <= V; ++i){
        G[i].clear();
        color[i] = 0;
    }
}
bool checkBipartite(int st){
    bool isBipartite = true;
    while(!q.empty())
        q.pop();
    q.push(st);
    color[st] = 1;
    while(!q.empty() && isBipartite){
        int u = q.front();
        q.pop();
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if(!color[v]){
                color[v] = 3-color[u];
                q.push(v);
            }
            else if(color[v] == color[u]){
                isBipartite = false;
                break;
            }
        }
    }
    return isBipartite;
}

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        scanf("%d%d", &V, &E);
        RESET();
        for(int i = 0; i < E; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        bool isBipartite = true;
        for(int i = 1; i <= V && isBipartite; ++i){
            if(!color[i]){
                isBipartite = isBipartite & checkBipartite(i);
            }
        }
        if(isBipartite)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
