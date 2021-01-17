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

const int N = 100010;
const int INF = 1e9;

int A[N], dp[2][N];

int main()
{
    int n, m;
    scanf("%*d%d%d", &n, &m);
    dp[0][0] = 0;
    for1(i, n) scanf("%d", &A[i]), dp[0][i] = INF;
    int ans = INF;
    for1(i, m) {
        int x = i&1;
        int mn = INF;
        for1(j, n) {
            mn = min(mn, dp[x^1][j-1]-A[j]+j);
            dp[x][j] = mn + (A[j]-j);
        }
        for1(j, n)
            printf("%d ", dp[x][j]);
        printf("\n");
        ans = min(ans, dp[x][n]);
    }
    printf("%d\n", ans);

    return 0;
}