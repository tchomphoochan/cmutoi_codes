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

const int N = 1010;
const int MOD = 1000003;

inline bool hasbit(int x, int i) { return x&(1<<i); }
inline int rembit(int x, int i) { return x&~(1<<i); }
inline void mod(int &x) { x %= MOD; }//while (x >= MOD) x -= MOD; }

int dp[N][1<<11];
vector<int> G[N];
int col[N];
/*bool did[N][1<<10];

int solve(int u, int p, int b)
{
    if (did[u][b]) return dp[u][b];
    int ans = 0;
    fora(v, G[u]) if (v != p) {
        ans += solve(v, u, rembit(b, col[u]));
        mod(ans);
    }
    did[u][b] = true;
    dp[u][b] = ans;
    return ans;
}*/

int main()
{
    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);
    forn(i, n) scanf("%d", &col[i]);
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    forn(b, 1<<c) {
        forn(u, n) {
            if (!hasbit(b, col[u])) continue;
            if ((b&-b) == b) {
                dp[u][b] = 1;
                continue;
            }
            fora(v, G[u]) {
                dp[u][b] += dp[v][rembit(b, col[u])];
                dp[u][b] %= MOD;
            }
        }
    }
    int ans = 0;
    forn(u, n) {
        ans += dp[u][(1<<c)-1];
        ans %= MOD;
    }
    printf("%d\n", ans);

    return 0;
}

