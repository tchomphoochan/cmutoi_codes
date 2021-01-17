#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int arr[N][N], dp[N][N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &arr[i][j]);
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
        }
    }

    printf("%d", dp[n][m]);

    return 0;
}