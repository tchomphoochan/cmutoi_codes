#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class NODE{
public:
    int u, w;
    NODE(int u, int w){
        this->u = u;
        this->w = w;
    }
};
class VERTEX{
public:
    int far1, far2, far3, far4;
};
int ma, Q[100005], V, E;
vector<int> G[100005];
vector<VERTEX> ver;
void RESET(){
    for(int i = 1; i <= V; ++i){
        G[i].clear();
    }
}

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        scanf("%d", &V);
        ver.resize(V+1);
        ma = -1;
        RESET();
        E = V-1;
        for(int i = 1; i <= V; ++i){
            scanf("%d", &Q[i]);
            ver[i].far1 = ver[i].far2 = ver[i].far3 = ver[i].far4;
        }
        for(int i = 1; i <= E; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        for(int i = 1; i <= 4; ++i){
            for(int u = 1; u <= V; ++u){
                for(int k = 0; k < G[u].size(); ++k){
                    int v = G[u][k];
                    ver[u].far1 = max(ver[u].far1, Q[v]);
                    ver[u].far2 = max(ver[u].far2, ver[v].far1);
                    ver[u].far3 = max(ver[u].far3, ver[v].far2);
                    ver[u].far4 = max(ver[u].far4, ver[v].far3);
                    ma = max(ma, ver[u].far4+Q[u]);
                }
            }
        }
        printf("%d\n", ma);
    }
    return 0;
}
/*
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class NODE{
public:
    int u, w;
    NODE(int u, int w){
        this->u = u;
        this->w = w;
    }
};
int ma, Q[100005], V, E;
bool visited[100005];
vector<int> G[100005];
queue<NODE> q;
void RESET(){
    for(int i = 1; i <= V; ++i){
        G[i].clear();
    }
}
void bfs(int st){
    while(!q.empty())
        q.pop();
    for(int i = 1; i <= V; ++i)
        visited[i] = false;
    q.push(NODE(st, 0));
    visited[st] = true;
    while(!q.empty()){
        int u = q.front().u, w = q.front().w;
        q.pop();
        if(w == 4){
            //printf("%d->%d\n", st, u);
            ma = max(ma, Q[st]+Q[u]);
            continue;
        }
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(NODE(v, w+1));
            }
        }
    }
}

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        scanf("%d", &V);
        ma = -1;
        RESET();
        E = V-1;
        for(int i = 1; i <= V; ++i)
            scanf("%d", &Q[i]);
        for(int i = 1; i <= E; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        for(int i = 1; i <= V; ++i){
            bfs(i);
        }
        printf("%d\n", ma);
    }
    return 0;
}
*/
/*
2
8
110 100 10 110 7 100 15 30
1 2
2 5
5 3
5 4
4 7
7 6
7 8
5
1 2 3 4 5
1 2
1 3
1 4
1 5
*/
