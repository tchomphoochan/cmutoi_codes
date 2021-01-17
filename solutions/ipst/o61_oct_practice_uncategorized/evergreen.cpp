#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const int X = 1000010;

bool has[X];
int near[X];
int mn = X, mx = 0;

ll cbush(int t)
{
    ll cnt = t*1LL*(t+1);
    for (int i = mn; i <= mx; ++i) {
        cnt += max(t-near[i]+1, 0);
    }
    return cnt;
}

int main()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        mn = min(mn, x);
        mx = max(mx, x);
        has[x] = true;
    }

    int lx = -INF;
    for (int i = mn; i <= mx; ++i) {
        if (has[i]) lx = i;
        near[i] = i-lx;
    }
    lx = INF;
    for (int i = mx; i >= mn; --i) {
        if (has[i]) lx = i;
        near[i] = min(near[i], lx-i);
    }

    int left = 0;
    int right = INF;
    while (left < right) {
        int mid = (left+right)/2;
        if (cbush(mid) >= k)
            right = mid;
        else
            left = mid+1;
    }
    printf("%d\n", right);

    return 0;
}