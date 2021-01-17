#include <stdio.h>

int n;
int l[200001] = {};
int ln = 0;

int li(int h)
{
    int b = 1;
    int e = ln;
    int m;

    while (e - b > 1)
    {
        m = (b + e) / 2;
        if (l[m] < h)
            b = m;
        else
            e = m;
    }

    return e;
}

int main(void)
{
    scanf("%d", &n);
    scanf("%d", &l[++ln]);

    for (int i = 1; i < n; i++)
    {
        int h;
        scanf("%d", &h);
        if (h > l[ln])
            l[++ln] = h;
        else if (h < l[1])
            l[1] = h;
        else
            l[li(h)] = h;
    }

    printf("%d", ln);
    return 0;
}