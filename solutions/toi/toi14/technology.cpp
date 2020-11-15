/**
 * toi14_technology
 * 
 * aquablitz11 (2019)
 * topological sorting using dfs
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int K = 10010;
const int INF = 1e9;

vector<int> G[N], L[K];
int cost = 0, col[N];

void solve(int u)
{
    if (col[u] == 1) cost = INF;
    if (col[u]) return;
    ++cost;
    col[u] = 1;
    for (auto v : G[u])
        solve(v);
    col[u] = 2;
}

int main()
{
    int n, k, t;
    scanf("%d%d%d", &n, &k, &t);
    for (int u = 1; u <= n; ++u) {
        int l, p;
        scanf("%d%d", &l, &p);
        L[l].push_back(u);
        for (int i = 0; i < p; ++i) {
            int x;
            scanf("%d", &x);
            G[u].push_back(x);
        }
    }

    int ans = -1;
    for (int l = 1; l <= k; ++l) {
        for (auto u : L[l])
            solve(u);
        if (cost <= t)
            ans = l;
        else
            break;
    }
    printf("%d\n", ans);
    
    return 0;
}