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

const int N = 1e5+10;

ll W[N];
unordered_map<ll, int> dp[N];

int solve(int i, ll w)
{
    if (w < 0) return -1e9;
    if (i == 0) return 0;
    if (dp[i].count(w)) return dp[i][w];
    ll nw = min(w-W[i], 6*W[i]);
    return dp[i][w] = max(solve(i-1, w), solve(i-1, nw)+1);
}

int main()
{
    time_t begin = clock();

    int T;
    scanf("%d", &T);
    for1(t, T) {
        int n;
        scanf("%d", &n);
        for1(i, n) scanf("%lld", &W[i]), dp[i].clear();
        printf("Case #%d: %d\n", t, solve(n, 1e18));
    }

    time_t end = clock();
    fprintf(stderr, "%.3f seconds\n", ((double)end-begin)/CLOCKS_PER_SEC);

    return 0;
}