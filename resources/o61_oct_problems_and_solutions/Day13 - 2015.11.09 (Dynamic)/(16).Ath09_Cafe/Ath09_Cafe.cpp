#include <cstdio>
#include <vector>
#include <algorithm>
#define SIZE 1000
using namespace std;
// dp[u] to max that u can answer
// childMem[u] to max that all child u can answer
int V, E, dp[SIZE+5]; /// Max val u can do
int childMem[SIZE+5]; /// Mem True DP of all child of u
vector<int> G[SIZE+5];

int dfsChildChildof(int u, int prev){
    int cnt = 0;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(v == prev)
            continue;
        cnt+=childMem[v];
    }
    return cnt;
}

int dfs(int u, int prev){
    int sumChild = 0;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(v == prev)
            continue;
        childMem[u]+=dfs(v, u);
    }
    int allChildChildofU = dfsChildChildof(u, prev), ret = 0;
    ret = max(ret, childMem[u]);
    ret = max(ret, allChildChildofU+1);
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(v == prev)
            continue;
        ret = max(ret, allChildChildofU-childMem[v]+dfsChildChildof(v, u) + 2);
        /// All child of child u that not have child of v exist + all child of child of v + 2 [mark u and v]
    }
    return dp[u] = ret;
}

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        scanf("%d", &V);
        E = V-1;
        for(int i = 1; i <= V; ++i){
            G[i].clear();
            dp[i] = childMem[i] = 0;
        }
        for(int i = 0; i < E; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        dfs(1, -1);
        printf("%d\n", dp[1]);
    }
    return 0;
}
/*
2
7
1 2
2 3
4 2
2 5
5 6
6 7
4
1 2
2 4
4 3
*/
