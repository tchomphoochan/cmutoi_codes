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

char s[15];
bool dp[15][15];

int main()
{
    int n, q;
    scanf("%d", &n);
    if (n > 10) {
        exit(0);
    }
    scanf(" %s%d", s+1, &q);
    for1(z, n) for1(i, n-z+1) {
        int j = i+z-1;
        if (z <= 2) dp[i][j] = s[i] == s[j];
        else dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        int cnt = 0;
        forx(i, l, r) forx(j, i, r) if (dp[i][j])
            ++cnt;
        printf("%d\n", cnt);
    }

    return 0;
}