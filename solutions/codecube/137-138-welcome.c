#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int found[4001] = {};
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        ++found[x];
    }

    if (found[2017] == 1)
    {
        printf("2017");
        return 0;
    }

    int ans1 = 0;
    for (int i = 2016; i >= 1; --i)
    {
        if (found[i] == 1)
        {
            ans1 = i;
            break;
        }
    }
    int ans2 = 4001;
    for (int i = 2018; i <= 4000; ++i)
    {
        if (found[i] == 1)
        {
            ans2 = i;
            break;
        }
    }

    if (ans1 == 0)
    {
        if (ans2 == 4001)
        {
            printf("-1");
            return 0;
        }
        printf("%d", ans2);
    }
    if (ans2 == 4001)
    {
        printf("%d", ans1);
        return 0;
    }
        
    if (abs(ans1 - 2017) <= abs(ans2 - 2017))
        printf("%d", ans1);
    else
        printf("%d", ans2);

    return 0;
}