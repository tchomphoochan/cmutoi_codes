#include <stdio.h>

int m, n, k;

int place[1001][1001] = {};
int sum[1001][1001] = {};

int main(void)
{
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &place[i][j]);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + place[i][j];
        }
    }

    int max = 0;
    for (int i = 1; i <= m - k + 1; i++)
    {
        for (int j = 1; j <= n - k + 1; j++)
        {
            int total = sum[i + k - 1][j + k - 1] - sum[i - 1][j + k - 1] - sum[i + k - 1][j - 1] + sum[i - 1][j - 1];
            if (total > max)
                max = total;
        }
    }

    printf("%d", max);

    return 0;
}