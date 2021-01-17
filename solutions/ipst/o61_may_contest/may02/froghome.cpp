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
#define fora(x, v) for (auto x : v)
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)

const int N = 100010;

vector<int> G[N];
int sz[N];
bool used[N];

void getsz(int u, int p)
{
    sz[u] = 1;
    fora(v, G[u]) if (v != p && !used[v]) {
        getsz(v, u);
        sz[u] += sz[v];
    }
}

int Q[N], _cnt[N], tim[N], tick;
inline int &cnt(int i) {
    if (tim[i] != tick) {
        tim[i] = tick;
        _cnt[i] = 0;
    }
    return _cnt[i];
}

int findcen(int u, int s, int p=0)
{
    fora(v, G[u]) if (!used[v] && v != p && sz[v] > sz[s]/2)
        return findcen(v, s, u);
    return u;
}

int qu;
ll ans;
void dfs(int u, int p, int l, int t)
{
    if (l > qu) return;
    if (t == 0) {
        ans += cnt(qu-l);
    } else {
        ++cnt(l);
    }
    fora(v, G[u]) if (v != p && !used[v])
        dfs(v, u, l+1, t);
}

void rec(int u)
{
    getsz(u, 0);
    u = findcen(u, u);
    ++tick;
    fora(v, G[u]) if (!used[v]) {
        dfs(v, u, 1, 0);
        dfs(v, u, 1, 1);
    }
    ans += cnt(qu);
    used[u] = true;
    fora(v, G[u]) if (!used[v])
        rec(v);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    assert(n >= 1);
    assert(n <= 100000);
    assert(k >= 1);
    assert(k <= 10);
    forn(i, k) scanf("%d", &Q[i]);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    forn(i, k) {
        ans = 0;
        qu = Q[i];
        assert(qu >= 1);
        assert(qu < n);
        for1(j, n)
            used[j] = false;
        rec(1);
        printf("%lld\n", ans*2);
    }

    return 0;
}