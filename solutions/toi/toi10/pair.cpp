/**
 * toi10_pair
 * 
 * aquablitz11 (2017)
 * 100/100
 */

#include <stdio.h>
#include <algorithm>

char c[1001] = {};
int dp[1001][1001] = {};

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf(" %c", &c[i]);

    for (int i = n; i >= 1; --i) {
        for (int j = i+1; j <= n; ++j) {
            // if in case i >= j dp[i][j] = 0
            int ans = dp[i+1][j];
            for (int k = i+1; k <= j; ++k) {
                if (c[i] == c[k])
                    ans = std::max(ans, dp[i+1][k-1] + dp[k+1][j] + 1);
            }
            dp[i][j] = ans;
        }
    }

    printf("%d", dp[1][n]);

    return 0;
}