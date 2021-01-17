#include <cstdio>
#include <vector>
#include <algorithm>
#define SIZE 100000
#define INF 1100000000
using namespace std;

int X[SIZE+5], ans;
bool can[SIZE+5];
vector<int> G[SIZE+5];

bool cmp(const int &A, const int &B){
    return A>B;
}

int dfs(int u, int prev){
    int ma = -INF;
    vector<int> vec;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(v == prev)
            continue;
        vec.push_back(dfs(v, u));
    }
    sort(vec.begin(), vec.end(), cmp);
    if(vec.size() == 1)
        ma = vec[0];
    else if(vec.size() > 1){
        ma = vec[0];
        if(vec[0] != -INF && vec[1] != -INF)
            ans = max(ans, vec[0]+vec[1]+X[u]);
    }
    if(ma == -INF && can[u] == false)
        ma = -INF;
    else if(ma == -INF && can[u] == true)
        ma = X[u];
    else if(ma != -INF && can[u] == true)
        ma = max(X[u], ma+X[u]);
    else if(ma != -INF && can[u] == false)
        ma = ma+X[u];
    if(can[u])
        ans = max(ans, ma);
    return ma;
}

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        int V, E;
        scanf("%d", &V);
        for(int i = 1; i <= V; ++i)
            G[i].clear();
        E = V-1;
        for(int i = 0; i < E; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        for(int i = 1; i <= V; ++i)
            scanf("%d", &X[i]);
        int st = -1;
        ans = -INF;
        for(int i = 1; i <= V; ++i){
            scanf("%d", &can[i]);
            if(can[i])
                st = i;
        }
        if(st == -1){
            printf("Stay Home\n");
            continue;
        }
        dfs(st, -1);
        if(ans <= 0)
            printf("Stay Home\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
/*
2
3
1 2
2 3
5 20 -10
1 0 1
4
1 2
2 3
3 4
-1 5 -20 -1
1 0 0 1

1
6
1 2
2 5
3 4
4 5
5 6
-2 10 13 10 2 -1
0 1 0 1 0 1
*/
