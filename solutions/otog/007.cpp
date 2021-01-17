#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int INF = 1e9;

int arr[N][N], dp[N][N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int ans;
    for (int i = 1; i <= n; ++i) {
        ans = INF;
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &arr[i][j]);
            dp[i][j] = dp[i-1][j] + arr[i][j];
            if (j != 1)
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + arr[i][j]);
            if (j != m)
                dp[i][j] = min(dp[i][j], dp[i-1][j+1] + arr[i][j]);
            ans = min(ans, dp[i][j]);
        }
    }
    printf("%d", ans);

    return 0;
}