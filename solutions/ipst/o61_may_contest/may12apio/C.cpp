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

const int N = 2e5+10;

using vi = vector<int>;

vector<int> G[N];

int disc[N], low[N], tick;
vector<vi> vc;
stack<int> S;
bool ap[N];
int id[N], sz[N];

void tarjan(int u, int p)
{
    S.push(u);
    disc[u] = low[u] = ++tick;
    int cnt = 0;
    fora(v, G[u]) {
        if (!disc[v]) {
            ++cnt;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if ((p == 0 && cnt > 1) || (p != 0 && low[v] >= disc[u]))
                ap[u] = true;
            if (low[v] >= disc[u]) {
                vc.pb({u});
                while (vc.back().back() != v) {
                    vc.back().pb(S.top());
                    S.pop();
                }
            }
        } else if (v != p) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

const int INF = 1e9;
ll ans = 0;
int cnt = 0, apcnt = 0;

int tsz[N];
bool used[N];

void getsz(int u, int p)
{
    tsz[u] = 1;
    fora(v, G[u]) if (v != p && !used[v]) {
        getsz(v, u);
        tsz[u] += tsz[v];
    }
}

pii cen;
void findcen(int u, int p, int s)
{
    int z = tsz[s]-tsz[u];
    fora(v, G[u]) if (v != p && !used[v]) {
        z = max(z, tsz[v]);
        findcen(v, u, s);
    }
    cen = min(cen, pii(z, u));
}

ll sumrs, sumps;

void dfs(int u, int p, ll ps, int t)
{
    ll rs = (u <= apcnt ? 1 : sz[u]-G[u].size());
    ps += sz[u]-1;

    if (t == 0) {
        ans += rs * (sumps - sumrs + (sumrs * ps));
    } else {
        sumrs += rs;
        sumps += rs*ps;
    }

    fora(v, G[u]) if (!used[v] && v != p)
        dfs(v, u, ps, t);
}

void rec(int u)
{
    cen = pii(INF, 0);
    getsz(u, 0);
    findcen(u, 0, u);
    u = cen.S;

    ll strs = (u <= apcnt ? 1 : sz[u]-G[u].size());
    ll stps = sz[u]-1;
    sumrs = strs;
    sumps = strs*stps;
    ans += (strs * (strs-1) * (sz[u]-2))/2;
    ll prev = 0;
    fora(v, G[u]) if (!used[v]) {
        dfs(v, u, 0, 0);
        dfs(v, u, stps, 1);
    }

    used[u] = true;
    fora(v, G[u]) if (!used[v])
        rec(v);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    for1(u, n) if (!disc[u])
        tarjan(u, 0);

    for1(u, n) {
        G[u].clear();
        if (ap[u]) {
            ++cnt, ++apcnt;
            sz[cnt] = 1;
            id[u] = cnt;
        }
    }
    fora(comp, vc) {
        ++cnt;
        sz[cnt] = comp.size();
        fora(u, comp) {
            if (ap[u]) {
                G[id[u]].pb(cnt);
                G[cnt].pb(id[u]);
            } else {
                id[u] = cnt;
            }
        }
    }

    /*for1(u, cnt) {
        printf("#%d (%d):", u, sz[u]);
        fora(v, G[u])
            printf(" %d", v);
        printf("\n");
    }*/

    for1(u, cnt) if (!used[u])
        rec(u);
    printf("%lld\n", ans*2);

    return 0;
}