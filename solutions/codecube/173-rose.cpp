#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define F first
#define S second

const int N = 100010;

int val[N], ix[N], parent[N];
vector<int> G[N];

int findroot(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = findroot(parent[u]);
}

using piii = pair<pii, int>;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val[i]);
        parent[i] = i;
        ix[i] = i;
    }
    sort(ix+1, ix+n+1, [&] (int a, int b) {
        return val[a] > val[b];
    });
    vector<piii> E;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        E.push_back({{u, v}, val[u]+val[v]});
    }
    sort(E.begin(), E.end(), [&] (piii a, piii b) {
        return a.S > b.S;
    });
    ll ans = 0;
    for (auto e : E) {
        int u, v, w;
        tie(u, v) = e.F;
        w = e.S;
        int ur = findroot(u);
        int vr = findroot(v);
        if (ur != vr) {
            parent[ur] = vr;
            ans += w;
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}