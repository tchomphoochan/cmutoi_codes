#include <stdio.h>
#include <stdlib.h>

int n;
int x[1000000];
int y[1000000];
int ix[1000000];
int stack[1000000];
int scount = 0;

int cmpfunc(const void *a, const void *b)
{
    int res = x[*(int*)a] - x[*(int*)b];
    if (res != 0)
        return res;
    else
        return y[*(int*)b] - y[*(int*)a];
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
        ix[i] = i;
    }
    qsort(ix, n, sizeof(int), &cmpfunc);

    int maxX = 0;
    int maxY = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        if (x[ix[i]] < maxX && y[ix[i]] < maxY)
            continue;
        
        if (x[ix[i]] > maxX)
            maxX = x[ix[i]];
        if (y[ix[i]] > maxY)
            maxY = y[ix[i]];

        stack[scount++] = ix[i];
    }

    while (scount > 0)
    {
        --scount;
        printf("%d %d\n", x[stack[scount]], y[stack[scount]]);
    }

    return 0;
}