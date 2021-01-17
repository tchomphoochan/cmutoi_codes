#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int cmpfunc(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int mod(int x, int m)
{
    return (x %= m) < 0 ? x + m : x;
}

int n, m;
char col;
int flips[100000];
int backs[100000];

int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &flips[i], &backs[i]);
        ++backs[i];
    }
    scanf(" %c", &col);
    if (col == 'R')
        col = 0;
    else if (col == 'G')
        col = 1;
    else // if (col == 'B')
        col = 2;

    qsort(flips, m, sizeof(int), &cmpfunc);
    qsort(backs, m, sizeof(int), &cmpfunc);

    int fi = 0;
    int bi = 0;
    ll count = 0;
    ll poke = 0;
    int prevMin = 1;
    while (fi < m && bi < m)
    {
        if (flips[fi] < backs[bi])
        {
            poke += (flips[fi] - prevMin) * mod(col - count, 3);

            ++count;
            prevMin = flips[fi];
            ++fi;
        }
        else
        {
            poke += (backs[bi] - prevMin) * mod(col - count, 3);

            --count;
            prevMin = backs[bi];
            ++bi;
        }
    }
    while (fi < m)
    {
        poke += (flips[fi] - prevMin) * mod(col - count, 3);

        ++count;
        prevMin = flips[fi];
        ++fi;
    }
    while (bi < m)
    {
        poke += (backs[bi] - prevMin) * mod(col - count, 3);

        --count;
        prevMin = backs[bi];
        ++bi;
    }
    poke += (n + 1 - prevMin) * mod(col - count, 3);

    printf("%lld", poke);
    return 0;
}