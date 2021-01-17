#include <stdio.h>

int main(void)
{
    int n, k, a;
    scanf("%d%d%d", &n, &k, &a);

    // p[i] = day number of page i
    int p[25] = {};
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        for (int j = total + 1; j <= total + x; ++j)
            p[j] = i;
        total += x;
    }

    // dp[i] = number of reachable page if start from page i
    int dp[25] = {};
    int best = 0;
    for (int i = total; i >= 1; --i)
    {
        dp[i] = (i + a > total ? 0 : dp[i + a])
        + (i + a > total ? 1 : (p[i] != p[i + a] ? 1 : 0))
        - (i + k*a > total ? 0 : (p[i + k*a] != p[i + (k-1)*a] ? 1 : 0));
        if (dp[i] >= dp[best])
            best = i;
    }

    printf("%d %d", best, dp[best]);

    return 0;
}