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

const int N = 1010;

vector<int> G[N];
int mxd = 0;
int dep[N];

void dfs(int u)
{
    fora(v, G[u]) {
        dep[v] = dep[u]+1;
        mxd = max(mxd, dep[v]);
        dfs(v);
    }
}

int cnt[N][N];

int main()
{
    int n, m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[v].pb(u);
    }
    dfs(0);
    forn(i, n) dep[i] = mxd-dep[i];
    forn(i, m) {
        int ki;
        scanf("%d", &ki);
        forn(j, ki) {
            int x;
            scanf("%d", &x);
            ++cnt[i][dep[x]];
            assert(cnt[i][dep[x]] <= 1);
        }
    }
    while (q--) {
        int qi;
        scanf("%d", &qi);
        int tt[N] = {};
        while (qi--) {
            int x;
            scanf("%d", &x);
            forn(i, mxd+1)
                tt[i] += cnt[x][i];
        }
        int car = 0, ans = 0;
        forn(i, mxd+1) {
            ans = i;
            int x = car+tt[i];
            car = x>>1;
            if (x&1)
                break;
        }
        printf("%d\n", ans);
    }

    return 0;
}