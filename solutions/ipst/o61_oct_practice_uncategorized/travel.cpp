#include <bits/stdc++.h>

using namespace std;

const int N = 30010;
const int LN = 20;

vector<int> G[N];
int level[N];
int parent[N][LN];

void dfs(int u, int p, int l)
{
    parent[u][0] = p;
    level[u] = l;
    for (auto v : G[u]) {
        if (v != p)
            dfs(v, u, l+1);
    }
}

int lca(int u, int v)
{
    if (level[u] > level[v]) swap(u, v);

    for (int i = LN-1; i >= 0; --i) {
        if (level[parent[v][i]] >= level[u])
            v = parent[v][i];
    }
    if (u == v) return u;

    for (int i = LN-1; i >= 0; --i) {
        if (level[parent[u][i]] != level[parent[v][i]]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int dist(int u, int v)
{
    int l = lca(u, v);
    return level[u] + level[v] - level[l]*2;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0, 1);
    for (int i = 1; i < LN; ++i) {
        for (int j = 1; j <= n; ++j) {
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }

    int m;
    scanf("%d", &m);
    int at = 1;
    int ans = 0;
    while (m--) {
        int x;
        scanf("%d", &x);
        ans += dist(at, x);
        at = x;
    }

    printf("%d", ans);
    return 0;
}