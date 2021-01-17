#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);

    bool cars[2000001] = {};
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        cars[x] = true;
    }

    int count = 0;
    for (int i = 2000000; i >= 1; i--)
    {
        if (cars[i])
        {
            if (++count == k)
            {
                printf("%d", i);
                break;
            }
        }
    }
    return 0;
}