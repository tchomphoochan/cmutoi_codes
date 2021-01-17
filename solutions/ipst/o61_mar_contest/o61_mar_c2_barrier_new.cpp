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

using dbl = double;
#define x first
#define y second

const int INF = 1e9;

int orien(pii a, pii b, pii c)
{
    ll val = (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y);
    if (val < 0) return -1; // counter-clockwise
    if (val > 0) return 1; // clockwise
    return 0; // colinear
}

double dist(pii a, pii b)
{
    ll dx = (a.x-b.x);
    ll dy = (a.y-b.y);
    return sqrt(dx*dx + dy*dy);
}

vector<pii> find_hull(vector<pii> pnt)
{
    sort(all(pnt));
    pnt.resize(unique(all(pnt))-pnt.begin());

    int n = pnt.size();
    pair<pii, int> mn(pii(INF, INF), -1);
    forn(i, n) mn = min(mn, {{pnt[i].y, pnt[i].x}, i});
    swap(pnt[0], pnt[mn.S]);
    sort(pnt.begin()+1, pnt.end(), [&] (pii a, pii c) {
        pii b = pnt[0];
        int o = orien(a, b, c);
        if (o == 1) return true;
        if (o == -1) return false;
        return dist(b,a) < dist(b,c);
    });

    vector<pii> hull;
    forn(i, n) {
        while (hull.size() >= 2) {
            pii a = hull[hull.size()-2];
            pii b = hull[hull.size()-1];
            pii c = pnt[i];
            int o = orien(a, b, c);
            if (o >= 0) hull.pop_back();
            else break;
        }
        hull.pb(pnt[i]);
    }

    return hull;
}

int main()
{
    int n;
    scanf("%d", &n);
    set<pii> pnt;
    pii mn(INF, INF);
    bool noco = true;
    forn(i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (pii(x, y) < mn) {
            pnt.emplace(x, y);
            find_hull(pnt);
        } else {
            modify_hull(pnt, );
        }
        double d = 0;
        for (auto it = pnt.begin(); next(it) != pnt.end(); ++it)
            d += dist(*it, *next(it));
        d += dist(*pnt.begin(), *prev(pnt.end()));
        printf("%.6f\n", d);
    }

    return 0;
}