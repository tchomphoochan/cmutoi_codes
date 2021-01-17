#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
const int MOD = 2553;

int dp[2][N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        if (i <= k)
            dp[0][i] = 1;
    }

    int ans = (((dp[0][n] * dp[0][n]) % MOD) * dp[0][n]) % MOD;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n; ++i)
            dp[1][i] = (dp[0][i-1] + dp[1][i-1] - dp[0][max(i-k-1,0)] + MOD) % MOD;
        for (int i = 1; i <= n; ++i)
            dp[0][i] = dp[1][i];
        ans += (((dp[0][n] * dp[0][n]) % MOD) * dp[0][n]) % MOD;
        ans %= MOD;
    }

    printf("%d", ans);

    return 0;
}