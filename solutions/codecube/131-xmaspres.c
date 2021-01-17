#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    int min1 = 1e9;
    int min2 = 1e9;
    while (n--)
    {
        int x;
        scanf("%d", &x);

        if (x < min1)
        {
            min2 = min1;
            min1 = x;
        }
        else if (x < min2)
        {
            min2 = x;
        }
    }

    int min3 = 1e9;
    int min4 = 1e9;
    while (m--)
    {
        int x;
        scanf("%d", &x);

        if (x < min3)
        {
            min4 = min3;
            min3 = x;
        }
        else if (x < min4)
        {
            min4 = x;
        }
    }

    int ans = min1 + min2;
    int ans2 = min3 + min4;
    if (ans2 < ans)
        ans = ans2;
    ans2 = min1 + min3 + 100;
    if (ans2 < ans)
        ans = ans2;
    
    printf("%d", ans);

    return 0;
}