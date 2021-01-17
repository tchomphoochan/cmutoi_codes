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

    auto cmprad = [&] (Circle a, Circle b) {
        if (a.r != b.r) return a.r > b.r;
        return a.ix < b.ix;
    };
    multiset<Circle, decltype(cmprad)> rad(cmprad);
    auto cmpleft = [&] (Circle a, Circle b) {
        if (a.x-a.r != b.x-b.r) return (a.x-a.r) < (b.x-b.r);
        return a.ix < b.ix;
    };
    multiset<Circle, decltype(cmpleft)> left(cmpleft);
    auto cmpright = [&] (Circle a, Circle b) {
        if (a.x+a.r != b.x+b.r) return (a.x+a.r) < (b.x+b.r);
        return a.ix < b.ix;
    };
    multiset<Circle, decltype(cmpright)> right(cmpright);

    auto add = [&] (Circle x) {
        rad.insert(x);
        left.insert(x);
        right.insert(x);
    };

    auto rem = [&] (Circle x) {
        auto it = rad.find(x);
        if (it != rad.end()) rad.erase(it);
        it = left.find(x);
        if (it != left.end()) left.erase(it);
        it = right.find(x);
        if (it != right.end()) right.erase(it);
    };

    forn(i, n) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        add({r, i, x, y});
    }

    while (!rad.empty()) {
        Circle c = *rad.begin();
        auto bnd = left.lower_bound(c);
        vector<Circle> torem;
        for (auto it = bnd; it != left.end(); ++it) {
            if (!overlap(c, *it)) break;
            torem.pb(*it);
        }
        bnd = --right.upper_bound(c);
        for (auto it = bnd; ; --it) {
            if (!overlap(c, *it)) break;
            torem.pb(*it);
            if (it == right.begin()) break;
        }
        fora(x, torem) {
            ans[x.ix] = c.ix;
            rem(x);
        }
    }

    forn(i, n) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]+1);
    }
    printf("\n");

    return 0;
}