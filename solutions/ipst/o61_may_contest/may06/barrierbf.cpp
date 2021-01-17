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

const int N = 510;

int qsr[N][N], qsc[N][N], cost[N][N];

int main()
{
    int n, m, r, c;
    scanf("%d%d%d%d", &n, &m, &r, &c);
    assert(n <= 150 && m <= 150);
    for1(i, n) for1(j, m) {
        scanf("%d", &cost[i][j]);
        qsr[i][j] = qsr[i][j-1]+cost[i][j];
        qsc[i][j] = qsc[i-1][j]+cost[i][j];
    }
    int mn = 1e9;
    forx(x1, 1, r-1) forx(x2, r+1, n)
    forx(y1, 1, c-1) forx(y2, c+1, m) {
        int cst = qsr[x1][y2]-qsr[x1][y1-1] + qsr[x2][y2]-qsr[x2][y1-1]
        + qsc[x2][y1]-qsc[x1-1][y1] + qsc[x2][y2]-qsc[x1-1][y2]
        - cost[x1][y1] - cost[x1][y2] - cost[x2][y1] - cost[x2][y2];
        mn = min(mn, cst);
    }
    printf("%d\n", mn);

    return 0;
}