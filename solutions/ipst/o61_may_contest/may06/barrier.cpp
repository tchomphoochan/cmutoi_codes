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

const int N = 510;
const int INF = 1e9;

int cost[N][N], in[N][N], out[N][N];
vector<int> G[N*N*2];
map<int, int> cap[N*N*2];

inline void addedge(int u, int v, int c=INF)
{
    G[u].pb(v);
    G[v].pb(u);
    cap[u][v] = c;
    //printf("%d %d %d\n", u, v, c);
}

int cnt = 0;
bool visited[N*N*2];
int lv[N*N*2];

bool bfs(int s, int t)
{
    fill(lv, lv+cnt+1, -1);
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
    fora(v, G[u]) if (lv[v] == lv[u]+1) {
        int x = dfs(v, t, min(c, cap[u][v]));
        if (x > 0) {
            cap[u][v] -= x;
            cap[v][u] += x;
            return x;
        }
    }
    return 0;
}

int dinic(int s, int t)
{
    int f = 0;
    while (bfs(s, t)) {
        int x;
        while ((x = dfs(s, t)) > 0)
            f += x;
    }
    return f;
}

int n, m, r, c;
int dist(int x, int y)
{
    return max(abs(r-x), abs(c-y));
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &r, &c);
    assert(n <= 50);
    assert(r > 1 && r < n && c > 1 && c < m);

    int src = ++cnt;
    int sink = ++cnt;
    for1(i, n) for1(j, m) {
        scanf("%d", &cost[i][j]);
        assert(cost[i][j] >= 0);
        assert(cost[i][j] <= 999);
        if (i == r && j == c) {
            in[i][j] = out[i][j] = src;
        } else {
            in[i][j] = ++cnt;
            out[i][j] = ++cnt;
            addedge(in[i][j], out[i][j], cost[i][j]);
            if (i == 1 || i == n || j == 1 || j == m)
                addedge(out[i][j], sink);
        }
    }
    assert(cnt < N*N*2);
    auto bound = [&] (int i, int j) {
        return i >= 1 && i <= n && j >= 1 && j <= m;
    };
    for1(i, n) for1(j, m) {
        forx(dx, -1, 1) forx(dy, -1, 1) if (dx != 0 || dy != 0) {
            if (bound(i+dx, j+dy))// && dist(i+dx, j+dy) >= dist(i, j))
                addedge(out[i][j], in[i+dx][j+dy]);
        }
    }

    /*for1(i, n) { for1(j, m) {
        printf("%d,%d\t", in[i][j], out[i][j]);
    } printf("\n"); }*/

    printf("%d\n", dinic(src, sink));

    return 0;
}
