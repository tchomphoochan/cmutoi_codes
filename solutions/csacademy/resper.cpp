#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2010;
const ll MOD = 1e9+7;

ll dp[N][N], qs[N][N];

int main()
{
    int n;
    scanf("%d", &n);
    dp[1][1] = qs[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 1; j <= i; ++j) {
            if (x == 0)
                dp[i][j] = qs[i-1][j-1];
            else
                dp[i][j] = (qs[i-1][i-1]-qs[i-1][j-1]+MOD)%MOD;
            qs[i][j] = (qs[i][j-1] + dp[i][j])%MOD;
        }
    }
    printf("%lld\n", qs[n][n]);

    return 0;
}
