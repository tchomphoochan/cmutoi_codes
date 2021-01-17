/**
 * toi12_weakpoint
 * 
 * aquablitz11 (2019)
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
vector<int> G[N];
int num, mxcnt = 0;

int tim = 0, pre[N], low[N], sz[N];
void dfs(int u, int p=0) {
    sz[u] = 1;
    pre[u] = low[u] = ++tim;
    int cnt = 0;
    for (auto v : G[u]) {
        if (!pre[v]) {
            dfs(v, u);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            if (low[v] >= pre[u])
                cnt += sz[v];
        } else if (v != p) {
            low[u] = min(low[u], pre[v]);
        }
    }
    if (p && (cnt > mxcnt || (cnt == mxcnt && u < num))) {
        mxcnt = cnt;
        num = u;
    }
}

int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(s);
    printf("%d\n%d\n", num, mxcnt);
    
    return 0;
}