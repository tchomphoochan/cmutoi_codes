#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e16;
const int N = 1e5+10;

ll arr[N], dp[N];

int main()
{
    int n;
    scanf("%d", &n);

    ll ans = -INF;
    dp[0] = dp[1] = -INF;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &arr[i]);
        if (i > 1) {
            dp[i] = max(dp[i-2]+arr[i-1]+arr[i], arr[i-1]+arr[i]);
            ans = max(ans, dp[i]);
        }
    }
    printf("%lld\n", ans);

    return 0;
}
