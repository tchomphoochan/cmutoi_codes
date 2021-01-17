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

struct Circle
{
    int r, ix, x, y;
    bool operator<(const Circle &rhs) const {
        if (r != rhs.r) return r > rhs.r;
        return ix < rhs.ix;
    }
};

ll dist(ll x1, ll x2, ll y1, ll y2)
{
    ll dx = x1-x2;
    ll dy = y1-y2;
    return dx*dx + dy*dy;
}

bool overlap(Circle a, Circle b)
{
    return dist(a.x, b.x, a.y, b.y) <= (a.r+b.r)*1ll*(a.r+b.r);
}

const int N = 3e5+10;

int ans[N];

int main()
{
    int n;
    scanf("%d", &n);
    vector<Circle> cir;
    forn(i, n) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        cir.pb({r, i, x, y});
    }

    while (!cir.empty()) {
        sort(all(cir));
        vector<Circle> newcir;
        fora(c, cir) {
            if (overlap(cir[0], c))
                ans[c.ix] = cir[0].ix;
            else
                newcir.pb(c);
        }
        cir = newcir;
    }

    forn(i, n) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]+1);
    }
    printf("\n");

    return 0;
}