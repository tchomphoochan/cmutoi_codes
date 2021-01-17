#include <cstdio>
#include <algorithm>

#define N 510
#define M 50010
#define MOD 1000007

int n, m;
int dp[M];
int ndp[M];

int main()
{
    scanf("%d%d", &n, &m);

    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j <= m; ++j) {
            ndp[j] = (dp[j] + (j-x >= 0 ? dp[j-x] : 0)) % MOD;
        }
        for (int j = 0; j <= m; ++j) {
            dp[j] = ndp[j];
            ndp[j] = 0;
        }
    }

    printf("%d", dp[m]);
    return 0;
}