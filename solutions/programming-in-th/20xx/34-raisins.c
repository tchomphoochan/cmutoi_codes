#include <stdio.h>

#define INF (9223372036854775807)
typedef long long ll;

int m, n;
int r[51][51] = {};
int suma[51][51] = {};
ll dp[51][51][51][51] = {};

int sum(int top, int left, int bottom, int right)
{
    return suma[bottom][right] - suma[top - 1][right] - suma[bottom][left - 1] + suma[top - 1][left - 1];
}

ll min(ll a, ll b)
{
    return a < b ? a : b;
}

ll divide(int top, int left, int bottom, int right)
{
    if (top == bottom && left == right)
        return 0;
    if (dp[top][left][bottom][right] != 0)
        return dp[top][left][bottom][right];
    
    ll best = INF;
    for (int i = left + 1; i <= right; ++i)
        best = min(best, divide(top, left, bottom, i - 1) + divide(top, i, bottom, right));
    for (int i = top + 1; i <= bottom; ++i)
        best = min(best, divide(top, left, i - 1, right) + divide(i, left, bottom, right));
    
    best += sum(top, left, bottom, right);
    dp[top][left][bottom][right] = best;
    return best;
}

int main(void)
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &r[i][j]);
            suma[i][j] = r[i][j] + suma[i - 1][j] + suma[i][j - 1] - suma[i - 1][j - 1];
        }
    }

    ll answer = divide(1, 1, m, n);
    printf("%lld", answer);

    return 0;
}