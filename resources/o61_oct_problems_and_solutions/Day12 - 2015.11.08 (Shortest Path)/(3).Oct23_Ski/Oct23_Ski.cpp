#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000000
using namespace std;

class NODE{
public:
    int u, w;
    NODE(int u, int w){
        this->u = u;
        this->w = w;
    }
};
int mi = INF, n;
bool visited[1005][2005];
vector<pair<int, int> > G[1005];
void shortestPath(int st, int S){
    queue<NODE> q;
    q.push(NODE(st, S));
    visited[st][S] = true;
    while(!q.empty()){
        int u = q.front().u, wS = q.front().w;
        //printf("%d %d\n", u, wS);
        q.pop();
        if(u <= n)
            mi = min(mi, wS);
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].first, w = G[u][i].second;
            if(wS-w >= 0 && !visited[v][wS-w]){
                q.push(NODE(v, wS-w));
                visited[v][wS-w] = true;
            }
        }
    }
}

int main(){
    int N, E, x, y;
    scanf("%d%d", &N, &n);
    scanf("%d", &E);
    for(int i = 0; i < E; ++i){
        scanf("%d%d", &x, &y);
        G[x].push_back(make_pair(y, 0));
    }
    scanf("%d", &E);
    for(int i = 0; i < E; ++i){
        int w;
        scanf("%d%d%d", &x, &y, &w);
        G[x].push_back(make_pair(y, w));
    }
    int st, S;
    scanf("%d%d", &st, &S);
    shortestPath(st, S);
    printf("%d", mi);
    return 0;
}
/*
#include <cstdio>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

class EDGE{
public:
    int u, v, w;
    EDGE(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int dp[2][1005][2];
bool inQ[1005][2];
vector<EDGE> edge;
vector<pair<int, int> > G[1005], Gt[1005];
void shortestPath(int t, int st){
    queue<pair<int, int> > q;
    dp[t][st][0] = 0;
    q.push(make_pair(st, 0));
    inQ[st][0] = true;
    while(!q.empty()){
        int u = q.front().first, use = q.front().second;
        q.pop();
        inQ[u][use] = false;
        if(t == 0){
            for(int i = 0; i < G[u].size(); ++i){
                int v = G[u][i].first, w = G[u][i].second, nU;
                if(w == 0)
                    nU = 0;
                else
                    nU = 1;
                if(dp[t][u][use] + w < dp[t][v][nU]){
                    dp[t][v][nU] = dp[t][u][use]+w;
                    if(!inQ[v][nU]){
                        q.push(make_pair(v, nU));
                        inQ[v][nU] = true;
                    }
                }
            }
        }
        else if(t == 1){
            for(int i = 0; i < Gt[u].size(); ++i){
                int v = Gt[u][i].first, w = Gt[u][i].second, nU;
                if(w == 0)
                    nU = 0;
                else
                    nU = 1;
                if(dp[t][u][use] + w < dp[t][v][nU]){
                    dp[t][v][nU] = dp[t][u][use]+w;
                    if(!inQ[v][nU]){
                        q.push(make_pair(v, nU));
                        inQ[v][nU] = true;
                    }
                }
            }
        }
    }
}

int main(){
    int N, n, E, x, y;
    scanf("%d%d", &N, &n);
    scanf("%d", &E);
    for(int i = 1; i <= N; ++i)
        dp[0][i][0] = dp[0][i][1] = dp[1][i][0] = dp[1][i][1] = INF;
    for(int i = 0; i < E; ++i){
        scanf("%d%d", &x, &y);
        edge.push_back(EDGE(x, y, 0));
        G[x].push_back(make_pair(y, 0));
        Gt[y].push_back(make_pair(x, 0));
    }
    scanf("%d", &E);
    for(int i = 0; i < E; ++i){
        int w;
        scanf("%d%d%d", &x, &y, &w);
        edge.push_back(EDGE(x, y, w));
        G[x].push_back(make_pair(y, w));
        Gt[y].push_back(make_pair(x, w));
    }
    int st, S;
    scanf("%d%d", &st, &S);
    shortestPath(0, st);
    shortestPath(1, n);
    for(int i = 1; i <= N; ++i){
        printf("%d->%d (%d)(%d)\n", st, i, dp[0][i][0], dp[0][i][1]);
    }
    for(int i = 1; i <= N; ++i){
        printf("%d->%d (%d)(%d)\n", n, i, dp[1][i][0], dp[1][i][1]);
    }
    return 0;
}
*/
/*
5 2
6
3 2
3 5
1 5
3 4
1 2
4 3
4
3 1 1
4 3 5
5 2 2
3 4 5
4 9
*/
