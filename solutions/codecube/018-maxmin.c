#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int min = 2e9;
    int max = -2e9;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x < min)
            min = x;
        if (x > max)
            max = x;
    }
    printf("%d\n%d", max, min);
    return 0;
}