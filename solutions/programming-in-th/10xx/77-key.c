#include <stdio.h>
//#include <time.h>

int d, k;

int place[1002][1002] = {};
int sum[1002][1002] = {};

int main(void)
{
    //clock_t begin = clock();
    scanf("%d%d", &d, &k);
    while (d--)
    {
        int r, c;
        scanf("%d%d", &r, &c);
        ++place[r + 1][c + 1];
    }

    for (int i = 1; i <= 1001; ++i)
    {
        for (int j = 1; j <= 1001; ++j)
            sum[i][j] = place[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }

    while (k--)
    {
        int r, c, p;
        scanf("%d%d%d", &r, &c, &p);
        int left = c - p;
        int up = r - p;
        int right = c + p + 1;
        if (right >= 1001)
            right = 1001;
        int down = r + p + 1;
        if (down >= 1001)
            down = 1001;
        int ans = sum[down][right];
        if (up >= 1)
            ans -= sum[up][right];
        if (left >= 1)
            ans -= sum[down][left];
        if (up >= 1 && left >= 1)
            ans += sum[up][left];
        printf("%d\n", ans);
    }

    //clock_t end = clock();
    //fprintf(stderr, "%.3f", ((double) end - begin) / CLOCKS_PER_SEC);
    return 0;
}