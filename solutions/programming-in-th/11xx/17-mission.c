#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
#define INF 9223372036854775807

int n;
int gain[100000];

int cmpfunc(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int e, g;
        scanf("%d%d", &e, &g);
        gain[i] = g - 2 * e;
    }
    qsort(gain, n, sizeof(int), &cmpfunc);

    ll max = -INF;
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += gain[i];
        ll notDone = n - i - 1;
        ll ans = sum - notDone * notDone;
        if (ans > max)
            max = ans;
    }

    printf("%lld", max);

    return 0;
}