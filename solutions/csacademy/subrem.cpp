#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e18;
const int N = 1e5+10;

ll arr[N], msl[N], msr[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]);
    msl[0] = -INF;
    msr[n+1] = -INF;

    ll dp = 0;
    for (int i = n; i >= 1; --i) {
        dp = max(arr[i]+dp, arr[i]);
        msr[i] = max(msr[i+1], dp);
    }

    ll ans = msr[2];
    dp = 0;
    for (int i = 1; i <= n; ++i) {
        dp = max(dp+arr[i], arr[i]);
        msl[i] = max(msl[i-1], dp);
        if (i <= n-2)
            ans = max(ans, msl[i]+msr[i+2]);
    }
    ans = max(ans, msl[n-1]);

    printf("%lld\n", ans);

    return 0;
}
