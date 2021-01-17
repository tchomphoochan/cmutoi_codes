#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define forx(i, a, b) for (int i = (a); i <= (b); ++i)
#define fora(x, v) for (auto x : v)

const int INF = 1e9;
const int N = 100010;
const int LN = 18;

int par[N][LN], mnv[N][LN], dep[N];

int main()
{
    int n;
    scanf("%d", &n);
    forn(i, LN) mnv[0][i] = INF;
    for1(u, n-1) {
        int p, w;
        scanf("%d%d", &p, &w);
        par[u][0] = p;
        dep[u] = dep[p]+1;
        mnv[u][0] = w;
    }
    for1(i, LN-1) {
        forn(u, N) {
            par[u][i] = par[par[u][i-1]][i-1];
            mnv[u][i] = min(mnv[u][i-1], mnv[par[u][i-1]][i-1]);
        }
    }
    int q, k, m, u, v;
    scanf("%d%d%d%d%d", &q, &k, &m, &u, &v);
    while (q--) {

        int u0 = u;
        int v0 = v;
        int ans = INF;

        if (u != v) {
            if (dep[u] > dep[v])
                swap(u, v);
            for (int i = LN-1; i >= 0; --i) {
                int nv = par[v][i];
                if (dep[nv] >= dep[u]) {
                    ans = min(ans, mnv[v][i]);
                    v = nv;
                }
            }
            if (u != v) {
                for (int i = LN-1; i >= 0; --i) {
                    int nu = par[u][i];
                    int nv = par[v][i];
                    if (nu != nv) {
                        ans = min(ans, mnv[u][i]);
                        ans = min(ans, mnv[v][i]);
                        u = nu;
                        v = nv;
                    }
                }
                ans = min(ans, mnv[u][0]);
                ans = min(ans, mnv[v][0]);
                u = par[u][0];
                v = par[v][0];
            }
        } else {
            ans = 0;
        }
        printf("%d\n", ans);

        int a3 = (v0*1LL*k + ans) % m % n;
        u = v0;
        v = a3;
    }

    return 0;
}