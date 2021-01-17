#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5+10;
const ll MOD = 1e9+7;

int n;
ll fact[N], invfact[N];
vector<int> G[N];
ll up[N], down[N], sz[N];

ll multi(ll a, ll b) { return (a*b)%MOD; }

ll power(ll a, ll b)
{
    ll r = 1;
    while (b > 0) {
        if (b&1)
            r = multi(r, a);
        a = multi(a, a);
        b >>= 1;
    }
    return r;
}

void push_up(int u, int p)
{
    ++sz[u];
    up[u] = 1;
    for (auto v : G[u]) {
        if (v != p) {
            push_up(v, u);
            sz[u] += sz[v];
            up[u] = multi(up[u], invfact[sz[v]]);
            up[u] = multi(up[u], up[v]);
        }
    }
    up[u] = multi(up[u], fact[sz[u]-1]);
}

void push_down(int u, int p)
{
    if (u == 1) {
        down[u] = up[u];
    } else {
        ll x = multi(down[p], fact[n-1-sz[u]]);
        x = multi(x, fact[sz[u]]);
        x = multi(x, invfact[n-1]);
        x = multi(x, power(up[u], MOD-2));
        down[u] = multi(fact[n-1], invfact[n-sz[u]]);
        down[u] = multi(down[u], x);
        for (auto v : G[u]) {
            if (v != p) {
                down[u] = multi(down[u], invfact[sz[v]]);
                down[u] = multi(down[u], up[v]);
            }
        }
    }

    for (auto v : G[u]) {
        if (v != p)
            push_down(v, u);
    }
}

int main()
{
    scanf("%d", &n);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = multi(fact[i-1], i);
        invfact[i] = power(fact[i], MOD-2);
    }

    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    push_up(1, 0);
    push_down(1, 0);
    
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans+down[i])%MOD;
    printf("%lld\n", ans);

    return 0;
}
