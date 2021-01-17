#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Event
{
    int xpos, col, h;
    bool operator<(const Event &rhs) const {
        return xpos < rhs.xpos;
    }
};

const int N = 1e6+10;
int ft[N];

void update(int i, int x) {
    for (; i < N; i += i&-i)
        ft[i] += x;
}

int query(int i) {
    if (i == 0) return 2e9;
    int ans = 0;
    for (; i > 0; i -= i&-i)
        ans += ft[i];
    return ans;
}

int bsearch(int t)
{
    int b = 0;
    int e = N-1;
    while (b < e) {
        int m = (b+e)/2;
        if (query(m) <= t)
            e = m;
        else
            b = m+1;
    }
    return b;
}

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    vector<Event> event;
    for (int i = 0; i < n; ++i) {
        int x, h, w, o;
        scanf("%d%d%d%d", &x, &h, &w, &o);
        event.push_back({x, o, h});
        event.push_back({x+w, -o, h});
    }
    sort(event.begin(), event.end());

    ll ans = 0;
    int last_x = 0;
    for (auto e : event) {
        ans += (ll)(e.xpos-last_x)*(bsearch(t-1)-bsearch(t));
        update(1, e.col);
        update(e.h+1, -e.col);
        last_x = e.xpos;
    }

    printf("%lld\n", ans);
    
    return 0;
}