#include <bits/stdc++.h>

using namespace std;

const int S = 510;
const int MOD = 1e9+7;

int dp[S][S], qs[S][S];

int main()
{
    int N, H;
    scanf("%d%d", &N, &H);
    dp[0][0] = 1;
    for (int h = 0; h <= H; ++h)
        qs[0][h] = 1;
    for (int n = 1; n <= N; ++n) {
        for (int h = 1; h <= H; ++h) {
            for (int i = 1; i <= n; ++i) {
                dp[n][h] += (1LL*dp[i-1][h-1]*qs[n-i][h-1])%MOD;
                dp[n][h] += (1LL*dp[n-i][h-1]*qs[i-1][h-2])%MOD;
                dp[n][h] %= MOD;
            }
            qs[n][h] = (qs[n][h-1]+dp[n][h]) % MOD;
        }
    }

    printf("%d\n", dp[N][H]);
    return 0;
}
