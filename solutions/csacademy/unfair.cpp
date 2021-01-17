#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5+10;
ll arr[N], dp[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]);
    sort(arr+1, arr+n+1);

    int bp;
    ll sum = 0;
    for (bp = n; bp >= 1 && arr[bp] >= 0; --bp)
        sum += arr[bp];
    if (bp < n) {
        ++bp;
        sum -= arr[bp];
    }

    dp[1] = arr[1];
    dp[2] = max(arr[2], arr[1]+arr[2]);
    for (int i = 3; i <= bp; ++i)
        dp[i] = max(arr[i]+dp[i-2], arr[i]+arr[i-1]+dp[i-3]);
    printf("%lld\n", dp[bp]+sum);

    return 0;
}
