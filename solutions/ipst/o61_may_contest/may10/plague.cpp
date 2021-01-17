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

const int N = 100010;
const int LN = 18;

int n, q;
vector<int> G[N];

// centroid stuff

int sz[N];
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

int dist[LN][N];
void makedist(int u, int p, int i)
{
    fora(v, G[u]) if (!used[v] && v != p) {
        dist[i][v] = dist[i][u]+1;
        makedist(v, u, i);
    }
}

void makect(int u, int p)
{
    getsz(u, 0);
    cen = pii(1e9, 0);
    findcen(u, 0, u);
    u = cen.S;
    cenpar[u] = p;
    cendep[u] = cendep[p]+1;
    makedist(u, 0, cendep[u]);
    used[u] = true;
    fora(v, G[u]) if (!used[v])
        makect(v, u);
}

// fenwick stuff

struct Fenwick
{
    int n;
    vector<int> ft;
    Fenwick() {}
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

// coordinate stuff

vector<int> coord[N], subcoord[N];
void makecoord(int u, int d)
{
    coord[u].pb(d);
    for (int v = u, p = cenpar[u]; p; v = p, p = cenpar[p]) {
        int di = dist[cendep[p]][u];
        if (d-di >= 0) {
            coord[p].pb(d-di);
            subcoord[v].pb(d-di);
        }
    }
}
void makecoord2(int u)
{
    coord[u].pb(0);
    for (int v = u, p = cenpar[u]; p; v = p, p = cenpar[p]) {
        int d = dist[cendep[p]][u];
        coord[u].pb(d);
        subcoord[u].pb(d);
    }
}
void compress(vector<int> &v)
{
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
}
int pos(vector<int> &v, int x)
{
    return lower_bound(all(v), x)-v.begin()+1;
}

// query stuff

Fenwick data[N], subdata[N];

inline void update(int u, int d)
{
    data[u].update(pos(coord[u], d));
    for (int v = u, p = cenpar[u]; p; v = p, p = cenpar[p]) {
        int di = dist[cendep[p]][u];
        if (d-di >= 0) {
            data[p].update(pos(coord[p], d-di));
            subdata[v].update(pos(subcoord[v], d-di));
        }
    }
}

inline int query(int u)
{
    int ans = data[u].query(pos(coord[u], 0));
    for (int v = u, p = cenpar[u]; p; v = p, p = cenpar[p]) {
        int d = dist[cendep[p]][u];
        //if (data[p].rbegin()->F >= d) {
        int add = data[p].query(pos(coord[p], d));
        int rem = subdata[v].query(pos(subcoord[v], d));
        ans += add-rem;
        //}
    }
    return ans;
}

int T[N], V[N], K[N];

int main()
{
    scanf("%d%d", &n, &q);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    makect(1, 0);

    forn(i, q) {
        int t, v, k;
        scanf("%d%d", &t, &v);
        if (t == 1) {
            scanf("%d", &k);
            makecoord(v, k);
        } else {
            makecoord2(v);
        }
        T[i] = t, V[i] = v, K[i] = k;
    }
    for1(i, n) {
        compress(coord[i]);
        compress(subcoord[i]);
        //printf("node %d:", i);
        //fora(x, coord[i]) printf(" %d", x);
        //printf(" |");
        //fora(x, subcoord[i]) printf(" %d", x);
        //printf("\n");
        data[i] = Fenwick(coord[i].size());
        subdata[i] = Fenwick(subcoord[i].size());
    }

    forn(i, q) {
        int t = T[i], v = V[i], k = K[i];
        if (t == 1) {
            update(v, k);
        } else {
            printf("%d\n", query(v));
        }
    }

    return 0;
}
