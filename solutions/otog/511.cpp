#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 3010;

int arr[N], dp[N][N], mn[N][N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k-1; ++j) {
            mn[i][j] = INF;
            dp[i][j] = INF;
        }
        for (int j = 1; j <= min(i, k-1); ++j) {
            dp[i][j] = mn[i-j][k-j] + arr[i];
            //printf("%d ", dp[i][j]);
        }
        //printf("\n");
        for (int j = 1; j <= k-1; ++j)
            mn[i][j] = min(mn[i][j-1], dp[i][j]);
    }

    int ans = INF;
    for (int i = n; i > n-k+1; --i)
        ans = min(ans, mn[i][k-(n-i)-1]);
    printf("%d\n", ans);
    return 0;
}