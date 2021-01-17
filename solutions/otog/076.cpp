#include <bits/stdc++.h>

using namespace std;

const int N = 50;
const int MOD = 2009;

int dp[N+10][N+10];

int main()
{
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= N; ++j) {
            dp[i][j] += dp[i-1][j];
            for (int lc = 1; lc <= i-1; ++lc) {
                int rc = i-1-lc;
                for (int lv = 0; lv <= j-1; ++lv) {
                    int rv = j-1-lv;
                    dp[i][j] += (dp[lc][lv] * dp[rc][rv]) % MOD;
                    dp[i][j] %= MOD;
                }
            }
        }
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", dp[n][k]);
    }

    return 0;
}