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

void solve(int n, int x, int y, int x1, int y1, int x2, int y2)
{
    if (n == 1) {
        int t = 1;
        if (x2 == x) ++t;
        if (y2 == y) t += 2;
        int c = ((x2/2 + y2/2) % 2 == 0) ? 2 : 3;
        printf("%d %d %d %d\n", t, c, x1, y1);
        return;
    }
    int xm = (x1+x2)/2;
    int ym = (y1+y2)/2;
    int X[] = {xm, xm+1, xm, xm+1};
    int Y[] = {ym, ym, ym+1, ym+1};
    int X1[] = {x1, xm+1, x1, xm+1};
    int Y1[] = {y1, y1, ym+1, ym+1};
    int X2[] = {xm, x2, xm, x2};
    int Y2[] = {ym, ym, y2, y2};
    forn(i, 4) {
        if (x >= X1[i] && x <= X2[i] && y >= Y1[i] && y <= Y2[i]) {
            printf("%d %d %d %d\n", i+1, 1, xm, ym);
            solve(n-1, x, y, X1[i], Y1[i], X2[i], Y2[i]);
        } else {
            solve(n-1, X[i], Y[i], X1[i], Y1[i], X2[i], Y2[i]);
        }
    }
}

int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    solve(n, x, y, 1, 1, 1<<n, 1<<n);

    return 0;
}