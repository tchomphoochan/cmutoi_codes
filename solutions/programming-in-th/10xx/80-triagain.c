#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int num[30000];
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    qsort(num, n, sizeof(int), &cmpfunc);

    int best = 1;
    int end = n - 1;
    for (int i = n - 2; i >= 0; --i)
    {
        while (num[i] + num[i + 1] <= num[end])
            --end;
        int dist = end - i + 1;
        if (dist > best)
            best = dist;
    }

    printf("%d", best);

    return 0;
}