#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

int n;
int x[500000];
int y[500000];

int cmpfunc(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);
    
    ll dist = 0;

    qsort(x, n, sizeof(int), &cmpfunc);
    qsort(y, n, sizeof(int), &cmpfunc);
    ll sumx = 0;
    ll sumy = 0;
    for (int i = 1; i < n; i++)
    {
        int diffx = (x[i] - x[i - 1]);
        sumx += diffx * i;
        int diffy = (y[i] - y[i - 1]);
        sumy += diffy * i;
        
        dist += sumx + sumy;
    }

    printf("%lld", dist);
    return 0;
}
