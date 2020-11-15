/**
 * toi14_plantation
 * 
 * aquablitz11 (2019)
 * closest pair of point using line sweep algorithm
 */

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
using pii = pair<int, int>;
const int INF = 1e9;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, r, d;
        scanf("%d%d%d", &n, &r, &d);
        vector<pii> circ;
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            circ.push_back({x, y});
        }
        sort(circ.begin(), circ.end());
        double mn = 1e9;
        auto cmp = [&] (pii a, pii b) {
            if (a.Y != b.Y) return a.Y < b.Y;
            return a.X < b.X;
        };
        set<pii, decltype(cmp)> Q(cmp);
        for (int i = 0; i < n; ++i) {
            auto &c1 = circ[i];
            auto lb = Q.lower_bound(pii(-INF, c1.Y-mn));
            auto ub = Q.upper_bound(pii(INF, c1.Y+mn));
            for (auto it = lb; it != ub; ) {
                auto &c2 = *it;
                double dx = c1.X-c2.X;
                if (dx > mn) {
                    auto nit = next(it);
                    Q.erase(it);
                    it = nit;
                } else {
                    double dy = c1.Y-c2.Y;
                    mn = min(mn, sqrt(dx*dx+dy*dy));
                    ++it;
                }
            }
            Q.insert(c1);
        }

        if (mn-2*r >= d)
            printf("Y\n");
        else
            printf("N\n");
    }
    
    return 0;
}