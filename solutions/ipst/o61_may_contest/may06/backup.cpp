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

const int N = 200010;
const int K = 22;
const int MOD = 10007;

int add(int a, int b) { return (a+b)%MOD; }
int mul(int a, int b) { return a*1ll*b%MOD; }

int powm(int a, int b, int m) {
    int ans = 1;
    while (b) {
        if (b&1) ans = (ans*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return ans;
}

int n, m, k;
vector<int> G[N];
int dp[N][K], deg[N], fact[K][K], C[K][K];

void solve(int u, int p)
{
    if (deg[u] == 1) {
        dp[u][1] = 1;
        return;
    }
    int l = 0, r = 0;
    fora(v, G[u]) if (v != p) {
        solve(v, u);
        if (l == 0) l = v;
        else r = v;
    }
    forx(c, 0, k) { // solve dp[u][c]
        //printf("\nsolving dp[%d][%d]\n", u, c);
        forx(lf, 0, k) { // leftover pairing
            forx(up, 0, c) { // left to go up, (right is c-up)
                if (up+lf <= k && (c-up)+lf <= k) {
                    //printf("left = %d, right = %d, pair %d pairs\n", up, c-up, lf);
                    int val = mul(dp[l][up+lf], dp[r][(c-up)+lf]);
                    //printf("val l*r = %d\n", val);
                    int pair = mul(C[up+lf][lf], fact[c-up+1][c-up+lf]);
                    //printf("pairing = C[%d][%d], fact[%d][%d], %d\n", up+lf, lf, c-up, c-up+lf, pair);
                    val = mul(val, pair);
                    dp[u][c] = add(dp[u][c], val);
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    C[0][0] = 1;
    for1(i, 2*k) C[i][0] = C[i][i] = 1;
    for1(i, 2*k) forx(j, 1, i-1)
        C[i][j] = add(C[i-1][j-1], C[i-1][j]);
    forx(i, 0, k*2) {
        int v = 1;
        forx(j, 0, max(i,1)-1)
            fact[i][j] = 1;
        forx(j, max(i,1), k*2) {
            v = mul(v, j);
            fact[i][j] = v;
        }
    }

    forn(i, m+n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
        ++deg[u], ++deg[v];
    }
    int s = 1;
    while (deg[s] != 2) ++s;
    solve(s, 0);
    /*for1(i, m+n) {
        printf("node %d:", i);
        forx(j, 0, k) printf(" %d", dp[i][j]);
        printf("\n");
    }*/
    printf("%d\n", dp[s][0]);

    return 0;
}