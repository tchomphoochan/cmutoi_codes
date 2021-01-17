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

using pli = pair<ll, int>;

const int N = 1260;
const ll INF = 1e18;

struct Segment
{
    int n;
    pli t[N<<1];
    Segment() {}
    Segment(int n) {
        this->n = n;
        forn(i, n) t[n+i] = pli(INF, i);
        rofn(i, n-1) t[i] = min(t[i<<1], t[i<<1|1]);
    }
    pli query(int l, int r)
    {
        --l, --r;
        pli ans(INF, 0);
        for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans = min(ans, t[l++]);
            if (r&1) ans = min(ans, t[--r]);
        }
        return ans;
    }
    void update(int i, ll x)
    {
        --i;
        int i0 = i;
        i += n;
        for (t[i] = min(t[i], pli(x, i0)); i >>= 1; )
            t[i] = min(t[i<<1], t[i<<1|1]);
    }
};

ll hi[N][N], qsr[N][N], qsc[N][N], dp[N][N];
Segment segr[N], segc[N];

void setvalue(int x, int y, ll v)
{
    dp[x][y] = v = min(dp[x][y], v);
    segr[x].update(y, dp[x][y] + qsr[x][y+1]);
    segc[y].update(x, dp[x][y] + qsc[x+1][y]);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pii> v;
    for1(i, n) for1(j, m) {
        scanf("%lld", &hi[i][j]);
        dp[i][j] = INF;
        v.eb(i, j);
    }
    for1(i, n) {
        segr[i] = Segment(m);
        rof1(j, m) qsr[i][j] = qsr[i][j+1] + hi[i][j];
    }
    for1(j, m) {
        segc[j] = Segment(n);
        rof1(i, n) qsc[i][j] = qsc[i+1][j] + hi[i][j];
    }
    sort(all(v), [&] (pii a, pii b) {
        if (hi[a.F][a.S] != hi[b.F][b.S])
            return hi[a.F][a.S] < hi[b.F][b.S];
        if (a.F != b.F)
            return a.F > b.F;
        return a.S > b.S;
    });

    fora(p, v) {
        int x = p.F;
        int y = p.S;
        if (x == 1 && y == 1) {
            setvalue(x, y, 0);
        } else {
            ll v1 = segr[x].query(1, y-1).F-qsr[x][y];
            ll v2 = segc[y].query(1, x-1).F-qsc[x][y];
            setvalue(x, y, min(v1, v2));
        }
    }
    printf("%lld\n", dp[n][m]);

    return 0;
}