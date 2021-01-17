#include <bits/stdc++.h>

using namespace std;

struct Data
{
    int x, y, v;
    bool operator<(const Data &b) const {
        return x < b.x || (x == b.x && v < b.v);
    }
};

const int N = 100010;

int ft[N];

void update(int x, int v)
{
    for (; x < N; x += x&(-x))
        ft[x] += v;
}

int query(int x)
{
    int ans = 0;
    for (; x > 0; x -= x&(-x))
        ans += ft[x];
    return ans;
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    vector<Data> dt;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        ++x1; ++y1; ++x2; ++y2;
        dt.push_back({x1, y1, 1});
        dt.push_back({x1, y2+1, -1});
        dt.push_back({x2+1, y1, -1});
        dt.push_back({x2+1, y2+1, 1});
    }

    vector<int> ans(m+2);
    for (int i = 2; i < m+2; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ++x; ++y;
        dt.push_back({x, y, i});
    }
    sort(dt.begin(), dt.end());

    for (auto d : dt) {
        if (d.v <= 1)
            update(d.y, d.v);
        else
            ans[d.v] = query(d.y);
    }

    for (int i = 2; i < m+2; ++i)
        printf("%d\n", ans[i]);

    return 0;
}