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

const int INF = 1e9;
const int N = 210;

int n, m, p, q;
int work[N][N], dist[N][N];

vector<int> G[2*N];
unordered_map<int, int> cap[2*N];
int lv[2*N];

bool bfs(int s, int t)
{
    fill(lv, lv+(2*p+2), -1);
    lv[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        fora(v, G[u]) if (lv[v] == -1 && cap[u][v]) {
            lv[v] = lv[u]+1;
            q.push(v);
        }
    }
    return lv[t] != -1;
}

int dfs(int u, int t, int c=INF)
{
    if (c <= 0)
        return 0;
    if (u == t)
        return c;
    int f = 0;
    fora(v, G[u]) if (lv[v] == lv[u]+1) {
        int x = dfs(v, t, min(c, cap[u][v]));
        cap[u][v] -= x;
        cap[v][u] += x;
        c -= x;
        f += x;
    }
    return f;
}

int dinic(int s, int t)
{
    int f = 0;
    while (bfs(s, t))
        f += dfs(s, t);
    return f;
}

void addedge(int u, int v)
{
    cap[u][v] = 1;
    G[u].pb(v);
    G[v].pb(u);
}

bool check(int tim, int lim)
{
    forn(i, 2*p+2) cap[i].clear(), G[i].clear();
    forn(i, p) forn(j, p) {
        int d = dist[work[tim][i]][work[tim+1][j]];
        if (d <= lim)
            addedge(i, p+j);
    }
    forn(i, p) {
        addedge(2*p, i);
        addedge(p+i, 2*p+1);
    }

    int f = dinic(2*p, 2*p+1);
    return f == p;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &p, &q);
    forn(i, q) forn(j, p) scanf("%d", &work[i][j]);
    forn(i, n) forn(j, n) if (i != j) dist[i][j] = INF;
    while (m--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }
    forn(k, n) forn(i, n) forn(j, n)
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    int mxd = 0;
    forn(i, n) forn(j, n) mxd = max(mxd, dist[i][j]);
    int tim = 0;
    forn(i, q-1) {
        int b = 0;
        int e = mxd;
        while (b < e) {
            int m = (b+e)/2;
            if (check(i, m))
                e = m;
            else
                b = m+1;
        }
        tim += b;
    }
    printf("%d\n", tim);

    return 0;
}