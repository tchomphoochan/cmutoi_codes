#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1100;

int n;
ll ft[N][N];

void update(int X, int Y, ll v)
{
    ++X; ++Y;
    for (int x = X; x <= n; x += x&-x) {
        for (int y = Y; y <= n; y += y&-y) {
            ft[x][y] += v;
        }
    }
}

ll query(int X, int Y)
{
    ++X; ++Y;
    ll ans = 0;
    for (int x = X; x > 0; x -= x&-x) {
        for (int y = Y; y > 0; y -= y&-y) {
            ans += ft[x][y];
        }
    }
    return ans;
}

int main()
{
    while (true) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            scanf("%d", &n);
        } else if (t == 1) {
            int x, y, a;
            scanf("%d%d%d", &x, &y, &a);
            update(x, y, a);
        } else if (t == 2) {
            int l, b, r, t;
            scanf("%d%d%d%d", &l, &b, &r, &t);
            ll ans = query(t, r) - query(t, l-1) - query(b-1, r) + query(b-1, l-1);
            printf("%lld\n", ans);
        } else {
            break;
        }
    }

    return 0;
}