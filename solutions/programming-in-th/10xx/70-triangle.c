#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int max = 0;
    int min = 2e9;
    int min2 = 2e9;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        if (x > max)
            max = x;
        if (x <= min)
        {
            min2 = min;
            min = x;
        }
        else if (x <= min2)
        {
            min2 = x;
        }
    }

    if (n >= 3 && min + min2 <= max)
        printf("yes");
    else
        printf("no");

    return 0;
}