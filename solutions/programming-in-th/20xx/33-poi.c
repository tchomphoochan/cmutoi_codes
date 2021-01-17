#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, t, p;

int taskCanDo[2000] = {};
int personTask[2001][2000] = {};
int personCount[2001] = {};
int personScore[2001] = {};
int ix[2001] = {};

int cmpfunc(const void *a, const void *b)
{
    int cmp = personScore[*(int*)b] - personScore[*(int*)a];
    if (cmp != 0)
        return cmp;

    cmp = personCount[*(int*)b] - personCount[*(int*)a];
    if (cmp != 0)
        return cmp;
    
    return *(int*)a - *(int*)b;
}

int main(void)
{
    scanf("%d%d%d", &n, &t, &p);
    for (int i = 1; i <= n; ++i)
    {
        ix[i] = i;
        for (int j = 0; j < t; ++j)
        {
            scanf("%d", &personTask[i][j]);
            if (personTask[i][j])
            {
                ++personCount[i];
                ++taskCanDo[j];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < t; ++j)
        {
            if (personTask[i][j])
                personScore[i] += n - taskCanDo[j];
        }
    }

    qsort(ix + 1, n, sizeof(int), &cmpfunc);
    for (int i = 1; i <= n; ++i)
    {
        if (ix[i] == p)
        {
            printf("%d %d", personScore[ix[i]], i);
            break;
        }
    }

    return 0;
}