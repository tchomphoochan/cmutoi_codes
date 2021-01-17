#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int n;
int wg[100000];
int we[100000];
int ix[100000];

int cmpfunc(const void *a, const void *b)
{
    return we[*(int*)a] - we[*(int*)b];
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        ix[i] = i;
        scanf("%d%d", &wg[i], &we[i]);
    }
    qsort(ix, n, sizeof(int), &cmpfunc);

    ll bestData = 0;
    int bestEnergy = 0;
    double bestRate = 0;

    ll data = 0;

    for (int i = 0; i < n; ++i)
    {
        data += wg[ix[i]];
        double rate = data / (double) we[ix[i]];
        if (rate > bestRate)
        {
            bestData = data;
            bestEnergy = we[ix[i]];
            bestRate = rate;
        }
    }

    printf("%lld %d", bestData, bestEnergy);
    return 0;
}