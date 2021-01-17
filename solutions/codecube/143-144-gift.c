#include <stdio.h>
#include <math.h>

int n, m;
int degree[30001] = {};
int count1 = 0;

int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ++degree[x]; ++degree[y];
        if (degree[x] == 1)
            ++count1;
        if (degree[x] == 2)
            --count1;
        if (degree[y] == 1)
            ++count1;
        if (degree[y] == 2)
            --count1;
    }

    printf("%.0lf", ceil(count1 / 2.0));

    return 0;
}