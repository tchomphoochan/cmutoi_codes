#include <stdio.h>

int main(void)
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    int best = 0;
    int ansX[5001] = {};
    int ansY[5001] = {};

    for (int i = 0; i < k; i++)
    {
        int x, y, r, start, end;
        scanf("%d%d%d", &x, &y, &r);

        start = (x - r >= 0 ? x - r : 0);
        end = (x + r <= n ? x + r : n);

        for (int j = start; j <= end; j++)
        {
            if (++ansX[j] > best)
                best = ansX[j];
        }

        start = (y - r >= 0 ? y - r : 0);
        end = (y + r <= m ? y + r : m);

        for (int j = start; j <= end; j++)
        {
            if (++ansY[j] > best)
                best = ansY[j];
        }
    }

    printf("%d", best);
    return 0;
}