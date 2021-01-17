#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define F first
#define S second

const int N = 100010;
const ll INF = 9e18;

int n;
vector<int> G[N];
ll cnt[N], dp[N], dp2[N], ans = INF;

void dfs(int u, int p)
{
    cnt[u] = 1;
    dp[u] = 0;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            cnt[u] += cnt[v];
            dp[u] += dp[v]+cnt[v];
        }
    }
}

void dfs2(int u, int p)
{
    if (p == 0)
        dp2[u] = dp[u];
    else
        dp2[u] = dp2[p] - 2*cnt[u] + n;
    ans = min(ans, dp2[u]);

    for (auto v : G[u]) {
        if (v != p)
            dfs2(v, u);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    printf("%lld\n", ans);
    
    return 0;
}