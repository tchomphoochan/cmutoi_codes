#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int divcount = 0;
    int divisor[10000] = {};
    double s = sqrt(n);
    for (int i = 1; i <= s; i++)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
            if (i != s)
                divisor[divcount++] = i;
        }
    }
    for (int i = divcount - 1; i >= 0; i--)
    {
        printf("%d ", n / divisor[i]);
    }

    return 0;
}