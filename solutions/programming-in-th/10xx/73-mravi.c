#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int l, t, n;
int pos[70000];

int mathShits(int a, int b)
{
    return (b / a) % 2 == 0 ? b % a : a - (b % a);
}

int calculate(int start, char way)
{
    if (start == 0)
        return mathShits(start, t);
    if (start == l)
        return l - mathShits(start, t);
    if (way == 'L')
        return l - calculate(l - start, 'D');
    if (start + t <= l)
        return start + t;
    return l - mathShits(l, t - (l - start));
}

int main(void)
{
    scanf("%d%d%d", &l, &t, &n);
    for (int i = 0; i < n; i++)
    {
        int start;
        char way;
        scanf("%d %c", &start, &way);
        pos[i] = calculate(start, way);
    }
    qsort(pos, n, sizeof(int), &cmpfunc);

    for (int i = 0; i < n; i++)
        printf("%d ", pos[i]);

    return 0;
}