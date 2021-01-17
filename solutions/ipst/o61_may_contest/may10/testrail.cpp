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

int main()
{
    int n, m, p, q;
    scanf("%d%d%d%d", &n, &m, &p, &q);
    assert(n <= 200);
    forn(i, q) {
        int x;
        forn(j, p)
            scanf("%d", &x);
    }
    forn(i, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
    }

    return 0;
}