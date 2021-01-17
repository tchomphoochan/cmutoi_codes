#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int bestB[1000000] = {};
int bestS[1000000] = {};

int place[1000000] = {};
int count[1000000] = {};

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            scanf("%d", &place[j]);
        qsort(place, m, sizeof(int), &cmpfunc);

        for (int j = 0; j < m; ++j)
        {
            if (i == 0 || place[j] > bestS[j])
            {
                bestB[j] = i;
                bestS[j] = place[j];
            }
        }
    }

    for (int i = 0; i < m; ++i)
        ++count[bestB[i]];
    
    int max = 0;
    for (int i = 1; i < n; ++i)
    {
        if (count[i] > count[max])
            max = i;
    }

    printf("%d", max + 1);
    return 0;
}