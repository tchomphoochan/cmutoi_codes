#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define F first
#define S second
#define forx(i, x, y) for (int i = (x); i <= (y); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rofx(i, x, y) for (int i = x; i >= y; --i)
#define rofn(i, n) for (int i = n-1; i >= 0; --i)
#define rof1(i, n) for (int i = n; i >= 1; --i)
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define fora(x, v) for (auto x : v)

using pil = pair<int, ll>;

const int N = 1010;

vector<pil> G[N];
unordered_set<ll> vis[N];
ll ans;

void solve(int u, int t, ll c=0)
{
    vis[u].insert(c);
    if (u == t) ans = max(ans, c);
    fora(v, G[u]) if (!vis[v.F].count(c^v.S))
        solve(v.F, t, c^v.S);
}

int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    forn(i, m) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        G[u].eb(v, w);
        G[v].eb(u, w);
    }
    while (q--) {
        for1(i, n) vis[i].clear();
        int u, v;
        ans = 0;
        scanf("%d%d", &u, &v);
        solve(u, v);
        printf("%lld\n", ans);
    }
   
    return 0;
}