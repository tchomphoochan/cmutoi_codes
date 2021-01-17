#include <stdio.h>

int main(void)
{
    unsigned k, n;
    scanf("%d %d", &k, &n);
    long ans = 0;
    for (int i = 0; i < k; i++)
    {
        unsigned mask = (1 << i);
        if ((n & mask) != 0)
            ans += (mask << 1) - 1;
    }
    printf("%ld", ans);
    return 0;
}