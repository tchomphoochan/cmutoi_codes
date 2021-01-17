#include <cstdio>
#include <algorithm>
#include <vector>
#define SIZE 100000
using namespace std;

vector<int> G[SIZE+5];
int W[SIZE+5], dp[SIZE+5];

int cntChildofV(int u, int prev){
    int cnt = 0;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(v == prev)
            continue;
        cnt+=dp[v];
    }
    return cnt;
}

int dfs(int u, int prev){
    int cntChild = 0, cntChildofChild = 0;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(v == prev)
            continue;
        cntChild+=dfs(v, u);
        cntChildofChild+=cntChildofV(v, u);
    }
    return dp[u] = max(cntChild, cntChildofChild+W[u]); /// Not use Node u || Use Node u
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &W[i]);
    for(int i = 1; i < N; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = dfs(0, -1);
    printf("%d", ans);
    return 0;
}
/*
5
3
2
10
10
10
0 1
1 2
3 1
0 4
*/
