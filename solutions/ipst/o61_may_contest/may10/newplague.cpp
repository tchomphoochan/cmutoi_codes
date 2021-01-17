//#pragma GCC optimize("Ofast")
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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 100010;
const int LN = 18;

int n, q;
vector<int> G[N];

// lca stuff

int sz[N], dep[N];
int par[N][LN];

void makelca(int u, int p)
{
    dep[u] = dep[p]+1;
    par[u][0] = p;
    for1(i, LN-1) par[u][i] = par[par[u][i-1]][i-1];

    sz[u] = 1;
    fora(v, G[u]) if (v != p) {
        makelca(v, u);
        sz[u] += sz[v];
    }
}

inline int lca(int u, int v)
{
    if (dep[u] > dep[v])
        swap(u, v);
    rofn(i, LN) {
        int nv = par[v][i];
        if (dep[nv] >= dep[u])
            v = nv;
    }
    if (u == v)
        return u;
    rofn(i, LN) {
        int nu = par[u][i];
        int nv = par[v][i];
        if (nu != nv)
            u = nu, v = nv;
    }
    return par[u][0];
}

inline int dist(int u, int v)
{
    int l = lca(u, v);
    return dep[u]+dep[v]-2*dep[l];
}

// centroid stuff

bool used[N];
int cenpar[N], cendep[N];

void getsz(int u, int p)
{
    sz[u] = 1;
    fora(v, G[u]) if (v != p && !used[v]) {
        getsz(v, u);
        sz[u] += sz[v];
    }
}

pii cen(1e9, 0);
void findcen(int u, int p, int s)
{
    int z = sz[s]-sz[u];
    fora(v, G[u]) if (v != p && !used[v]) {
        z = max(z, sz[v]);
        findcen(v, u, s);
    }
    cen = min(cen, {z, u});
}

void makect(int u, int p)
{
    getsz(u, 0);
    cen = pii(1e9, 0);
    findcen(u, 0, u);
    u = cen.S;
    cenpar[u] = p;
    cendep[u] = cendep[p]+1;
    used[u] = true;
    fora(v, G[u]) if (!used[v])
        makect(v, u);
}

ordered_set<pii> data[N], subdata[N];

struct Fenwick
{
    int n;
    vector<int> ft;
    Fenwick(int n) : n(n), ft(n+1, 0) {}
    int query(int i) {
        int ans = 0;
        for (; i <= n; i += i&-i)
            ans += ft[i];
        return ans;
    }
    void update(int i) {
        for (; i > 0; i -= i&-i)
            ++ft[i];
    }
};

vector<int> coord[N], subcoord[N];
void makecoord(int u, int d)
{
    coord[u].pb(d);
    for (int v = u, p = cenpar[u]; p; v = p, p = cenpar[p]) {
        coord[p].pb(d-dist(u, p));
        subcoord[v].pb(d-dist(u, p));
    }
}
void makecoord2(int u)
{
    coord[u].pb(0);
    for (int v = u, p = cenpar[u]; p; v = p, p = cenpar[p]) {
        coord[u].pb(dist(u, p));
        subcoord[u].pb(dist(u, p));
    }
}

inline void update(int u, int d)
{
    data[u].insert({d, q});
    for (int v = u, p = cenpar[u]; p; v = p, p = cenpar[p]) {
        int di = dist(u, p);
        if (d-di >= 0) {
            data[p].insert({d-di, q});
            subdata[v].insert({d-di, q});
        }
    }
}

inline int query(int u)
{
    int ans = data[u].size();
    for (int v = u, p = cenpar[u]; p; v = p, p = cenpar[p]) {
        int d = dist(u, p);
        int add = data[p].size() - data[p].order_of_key({d, -1});
        int rem = subdata[v].size() - subdata[v].order_of_key({d, -1});
        ans += add-rem;
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &q);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    makelca(1, 0);
    makect(1, 0);

    while (q--) {
        int t, v, k;
        scanf("%d%d", &t, &v);
        if (t == 1) {
            scanf("%d", &k);
            update(v, k);
        } else {
            printf("%d\n", query(v));
        }
    }

    return 0;
}