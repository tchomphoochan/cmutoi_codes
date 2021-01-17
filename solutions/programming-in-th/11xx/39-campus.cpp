#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const int N = 500010;

int n, x[N], y[N], m[N];

ll costx(ll xm)
{
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans += abs(x[i]-xm) * m[i];
    return ans;
}

ll costy(ll ym)
{
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans += abs(y[i]-ym) * m[i];
    return ans;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", &x[i], &y[i], &m[i]);

    int l = 1, r = INF;
    while (r-l > 1) {
        int mid = (l+r)/2;
        if (costx(mid) >= costx(mid+1)) l = mid;
        else r = mid;
    }
    ll ans = min(costx(l), costx(r));

    l = 1, r = INF;
    while (r-l > 1) {
        int mid = (l+r)/2;
        if (costy(mid) >= costy(mid+1)) l = mid;
        else r = mid;
    }
    ans += min(costy(l), costy(r));

    printf("%lld", ans);
    return 0;
}