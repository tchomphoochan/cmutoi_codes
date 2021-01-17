#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6+10;

ll dp[N];

int main()
{
    int n;
    scanf("%d", &n);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 500*i;
        dp[i] = min(dp[i], 500 + dp[i-1]);
        dp[i] = min(dp[i], 800 + dp[i-2]);
        dp[i] = min(dp[i], 1500 + dp[i-5]);
        dp[i] = min(dp[i], 3000 + dp[i-15]);
    }

    printf("%lld", dp[n]);

    return 0;
}