#include <stdio.h>

int qs[1000001] = {};
int n, y, x, d, q, i = 2, s, e;

int main(void)
{
    scanf("%d", &n);
    scanf("%d", &y);

    for (; i <= n; ++i)
    {
        scanf("%d", &x);
        d = x - y;
        qs[i] = qs[i - 1] + (d < 0 ? 0 : d);
        y = x;
    }

    scanf("%d", &q);

    while (q--)
    {
        scanf("%d%d", &s, &e);
        printf("%d\n", qs[e] - qs[s]);
    }

    return 0;
}