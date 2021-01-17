#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int V, E, color[100005];
pair<int, int> edge[100005];
vector<int> G[100005];
queue<int> q;
void RESET(){
    for(int i = 1; i <= V; ++i){
        G[i].clear();
        color[i] = 0;
    }
}
bool checkBipartite(int st){
    while(!q.empty())
        q.pop();
    q.push(st);
    color[st] = 1;
    bool isBipartite = true;
    while(!q.empty() && isBipartite){
        int u = q.front();
        q.pop();
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if(!color[v]){
                color[v] = 3-color[u];
                q.push(v);
            }
            else if(color[u] == color[v]){
                isBipartite = false;
                break;
            }
        }
    }
    return isBipartite;
}

int main(){
    scanf("%d%d", &V, &E);
    for(int i = 1; i <= E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        edge[i] = make_pair(x, y);
    }
    int lastDay, L = 1, R = E, mid;
    while(L <= R){
        mid = (L+R)/2;
        RESET();
        for(int i = 1; i <= mid; ++i){
            int x = edge[i].first, y = edge[i].second;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        bool isBipartite = true;
        for(int i = 1; i <= V && isBipartite; ++i){
            if(!color[i]){
                isBipartite = isBipartite & checkBipartite(i);
            }
        }
        if(isBipartite){
            lastDay = mid;
            L = mid+1;
        }
        else
            R = mid-1;
    }
    printf("%d", lastDay);
    return 0;
}
