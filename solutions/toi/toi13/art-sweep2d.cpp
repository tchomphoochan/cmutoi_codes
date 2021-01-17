#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct YEvent
{
    int ypos, val;
    bool operator<(const YEvent &rhs) const {
        if (ypos != rhs.ypos)
            return ypos < rhs.ypos;
        return val < rhs.val;
    }
};

struct XEvent
{
    int xpos, type, col, h;
    bool operator<(const XEvent &rhs) const {
        return xpos < rhs.xpos;
    }
};

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    vector<XEvent> xevent;
    for (int i = 0; i < n; ++i) {
        int x, h, w, o;
        scanf("%d%d%d%d", &x, &h, &w, &o);
        xevent.push_back({x, 1, o, h});
        xevent.push_back({x+w, -1, o, h});
    }
    sort(xevent.begin(), xevent.end());

    multiset<YEvent> yevent;
    ll ans = 0;
    int last_x = 0;
    for (auto xe : xevent) {
        int sum = 0, last_y = 0, cnt = 0;
        for (auto ye : yevent) {
            if (cnt == t)
                sum += ye.ypos-last_y;
            cnt += ye.val;
            last_y = ye.ypos;
        }
        ans += (ll)(xe.xpos-last_x)*sum;

        last_x = xe.xpos;
        if (xe.type == 1) {
            yevent.insert({0, xe.col});
            yevent.insert({xe.h, -xe.col});
        } else {
            yevent.erase(yevent.find({0, xe.col}));
            yevent.erase(yevent.find({xe.h, -xe.col}));
        }
    }

    printf("%lld\n", ans);
    
    return 0;
}