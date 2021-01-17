#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 40000000000
#define SIZE 100000
using namespace std;

class NODE{
public:
    int u, down;
    long long now;
    NODE(int u, int down, long long now){
        this->u = u;
        this->down = down;
        this->now = now;
    }
};
struct cmp{
    bool operator()(const NODE &A, const NODE &B){
        return !(A.now < B.now);
    }
};
int V, E, K;
long long dp[SIZE+5][6];
bool visited[SIZE+5][6];
priority_queue<NODE, vector<NODE>, cmp> q;
vector<pair<int, int> > G[SIZE+5];
void shortestPath(){
    q.push(NODE(1, 0, 0));
    dp[1][0] = 0;
    while(!q.empty()){
        int u = q.top().u, d = q.top().down;
        long long now = q.top().now;
        q.pop();
        if(visited[u][d])
            continue;
        dp[u][d] = now;
        //printf("U:%d D:%d W:%d\n", u, d, now);
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].first, w = G[u][i].second;
            if(w < -100 && d < K && !visited[v][d+1])
                q.push(NODE(v, d+1, now));
            else if(w >= -100 && w <= 0 && !visited[v][d])
                q.push(NODE(v, d, now));
            else if(w > 0 && !visited[v][d])
                q.push(NODE(v, d, now+w));
        }
        visited[u][d] = true;
    }
}

int main(){
    scanf("%d%d%d", &V, &E, &K);
    for(int i = 1; i <= V; ++i){
        for(int j = 0; j <= K; ++j)
            dp[i][j] = INF;
    }
    for(int i = 0; i < E; ++i){
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        G[x].push_back(make_pair(y, w));
    }
    shortestPath();
    long long ans = INF;
    for(int i = 0; i <= K; ++i)
        ans = min(ans, dp[V][i]);
    if(ans == INF)
        printf("-1");
    else
        printf("%lld", ans);
    return 0;
}
/*
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000000000
#define SIZE 100000
using namespace std;

class NODE{
public:
    int u, down;
    NODE(int u, int down){
        this->u = u;
        this->down = down;
    }
};
int V, E, K;
long long dp[SIZE+5][6];
bool inQ[SIZE+5][6];
queue<NODE> q;
vector<pair<int, int> > G[SIZE+5];
void shortestPath(){
    q.push(NODE(1, 0));
    dp[1][0] = 0;
    inQ[1][0] = true;
    while(!q.empty()){
        int u = q.front().u, d = q.front().down;
        q.pop();
        inQ[u][d] = false;
        //printf("U:%d D:%d\n", u, d);
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].first, w = G[u][i].second;
            if(w < -100 && d < K && dp[u][d] < dp[v][d+1]){
                dp[v][d+1] = dp[u][d];
                if(!inQ[v][d+1]){
                    q.push(NODE(v, d+1));
                    inQ[v][d+1] = true;
                }
            }
            else if(w >= -100 && w <= 0 && dp[u][d] < dp[v][d]){
                //printf("%d->%d (%d) (%d)\n", u, v, dp[u][d], w);
                dp[v][d] = dp[u][d];
                if(!inQ[v][d]){
                    q.push(NODE(v, d));
                    inQ[v][d] = true;
                }
            }
            else if(w > 0 && dp[u][d] + w < dp[v][d]){
                //printf("%d->%d (%d) (%d)\n", u, v, dp[u][d], w);
                dp[v][d] = dp[u][d]+w;
                if(!inQ[v][d]){
                    q.push(NODE(v, d));
                    inQ[v][d] = true;
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &V, &E, &K);
    for(int i = 1; i <= V; ++i){
        for(int j = 0; j <= K; ++j)
            dp[i][j] = INF;
    }
    for(int i = 0; i < E; ++i){
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        G[x].push_back(make_pair(y, w));
    }
    shortestPath();
    long long ans = INF;
    for(int i = 0; i <= K; ++i)
        ans = min(ans, dp[V][i]);
    printf("%lld", ans);
    return 0;
}
*/
/*
5 6 0
1 2 1
2 3 -1
1 3 5
3 4 2
4 5 -200
3 5 4
*/
