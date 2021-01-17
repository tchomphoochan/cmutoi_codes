#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int N = 1010;
const int S = 27;

int n;
char s[N];
int dp[N][N][S];

int main()
{
    scanf("%s", s+1);
    n = strlen(s+1);

    for (int z = 1; z <= n; ++z) {
        for (int c = 0; c < 26; ++c) {
            for (int i = 1; i <= n-z+1; ++i) {
                int j = i+z-1;
                if (z == 1) {
                    dp[i][j][c] = s[i]-'a' == c ? 1 : 0;
                } else if (s[i]-'a' != c || s[j]-'a' != c) {
                    dp[i][j][c] += dp[i+1][j][c];
                    dp[i][j][c] %= MOD;
                    dp[i][j][c] += dp[i][j-1][c];
                    dp[i][j][c] %= MOD;
                    dp[i][j][c] += MOD-dp[i+1][j-1][c];
                    dp[i][j][c] %= MOD;
                } else {
                    dp[i][j][c] = 2;
                    for (int k = 0; k < 26; ++k) {
                        dp[i][j][c] += dp[i+1][j-1][k];
                        dp[i][j][c] %= MOD;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans += dp[1][n][i];
        ans %= MOD;
    }
    printf("%d\n", ans);

    return 0;
}
