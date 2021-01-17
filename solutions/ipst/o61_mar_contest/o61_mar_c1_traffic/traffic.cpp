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

#include "traffic.h"

int n, k;
int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;

void set_ans(int x1, int y1, int x2, int y2) {
    if (ax1 == 0)
        ax1 = x1, ay1 = y1, ax2 = x2, ay2 = y2;
    else
        bx1 = x1, by1 = y1, bx2 = x2, by2 = y2;
}

void solve1(int i, int sw, int l=1, int r=n)
{
    while (r-l > 1) {
        int m = (l+r)/2;
        int x = !sw ? traffic_query(i, l, i, m) : traffic_query(l, i, m, i);
        if (x > m-l)
            r = m;
        else
            l = m;
    }
    if (!sw) set_ans(i, l, i, r);
    else set_ans(l, i, r, i);
}

void solve2(int i, int sw)
{
    int l = 1;
    int r = n;
    while (r-l > 1) {
        int m = (l+r)/2;
        int x = !sw ? traffic_query(i, l, i, m) : traffic_query(l, i, m, i);
        if (x == m-l+2) {
            r = m;
        } else if (x == m-l) {
            l = m;
        } else {
            solve1(i, sw, l, m);
            solve1(i, sw, m, r);
            return;
        }
    }
    assert(false);
}

int main()
{
    traffic_init(&n, &k);
    for (int i = 1; i <= n; ++i) {
        int x = traffic_query(i, 1, i, n);
        if (x == n) solve1(i, 0);
        else if (x == n+1) solve2(i, 0);
    }
    for (int i = 1; i <= n; ++i) {
        int x = traffic_query(1, i, n, i);
        if (x == n) solve1(i, 1);
        else if (x == n+1) solve2(i, 1);
    }

    traffic_report(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);

    return 0;
}