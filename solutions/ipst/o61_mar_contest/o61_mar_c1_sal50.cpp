#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) begin(x), end(x)
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define forx(i, a, b) for (int i = (a); i <= (b); ++i)
#define rofn(i, n) for (int i = (n)-1; i >= 0; --i)
#define rof1(i, n) for (int i = (n); i > 0; --i)
#define rofx(i, a, b) for (int i = (a); i >= (b); --i)

const int N = 100010;
const int INF = 1e9;

#define pb push_back
#define fora(x, v) for (auto x : v)

int val[N];
vector<int> G[N];
map<int, int> dp[N];

int solve(int u, int c)
{
    if (dp[u].count(c))
        return dp[u][c];
    int c1 = 0;
    fora(v, G[u]) c1 += solve(v, c);
    int c2 = 0;
    if (val[u] <= c) {
        c2 = 1;
        fora(v, G[u])
            c2 += solve(v, val[u]);
    }
    return dp[u][c] = max(c1, c2);
}

int main()
{
    int n;
    scanf("%d", &n);
    assert(n <= 100000);
    forn(i, n) {
        scanf("%d", &val[i]);
        assert(val[i] >= 1 && val[i] <= 1000000);
    }
    return 0;

    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
    }
    printf("%d\n", n-solve(0, INF));
    
    return 0;
}