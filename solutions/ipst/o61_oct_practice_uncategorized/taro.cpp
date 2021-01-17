#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+1;
const int N = 100010;
const int K = 300;

int main()
{
    int c;
    scanf("%d", &c);
    while (c--) {

        int n, k, dp[K], ndp[K];
        scanf("%d%d", &n, &k);
        for (int i = 0; i <= 2*k; ++i)
            dp[i] = INF;
        dp[k] = 0;
        int ans;
        for (int i = 1; i <= n; ++i) {
            ans = INF;
            int a, b;
            scanf("%d%d", &a, &b);
            for (int j = 0; j <= 2*k; ++j) {
                ndp[j] = INF;
                if (j-1 >= 0) ndp[j] = min(ndp[j], dp[j-1] + a);
                if (j+1 <= 2*k) ndp[j] = min(ndp[j], dp[j+1] + b);
                ans = min(ans, ndp[j]);
            }
            for (int j = 0; j <= 2*k; ++j) {
                dp[j] = ndp[j];
                ndp[j] = INF;
            }
        }
        printf("%d\n", ans);

    }

    return 0;
}