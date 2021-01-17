#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int N = 110;

int dp[N][N], qsi[N][N], qsj[N][N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            for (int tr = i; tr >= 1; --tr) {
                for (int len = 1; len <= k; ++len) {
                    int tl = tr-len;
                    if (tl < 1)
                        break;    
                    dp[i][j] += (qsi[tl-1][j-1]+j) % MOD;
                    dp[i][j] %= MOD;
                    /*for (int b = 1; b <= j; ++b) {
                        dp[i][j] += dp[tl-1][b-1]+1;
                        dp[i][j] %= MOD;
                    }*/
                }
            }

            for (int br = j; br >= 1; --br) {
                for (int len = 1; len <= k; ++len) {
                    int bl = br-len;
                    if (bl < 1)
                        break;
                    dp[i][j] += (qsj[i-1][bl-1]+i) % MOD;
                    dp[i][j] %= MOD;
                    /*for (int t = 1; t <= i; ++t) {
                        dp[i][j] += dp[t-1][bl-1]+1;
                        dp[i][j] %= MOD;
                    }*/
                }
            }

            qsi[i][j] = (qsi[i][j-1] + dp[i][j]) % MOD;
            qsj[i][j] = (qsj[i-1][j] + dp[i][j]) % MOD;

        }
    }

    ans = dp[n][n];
    printf("%d", ans);
    return 0;
}