#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int n;
int t[1000001];

int main(void)
{
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &t[i]);

    ull from3toN = 0;
    for (int i = 3; i <= n; ++i)
        from3toN += t[i];
    
    ull rem = 0;
    ull min = 9223372036854775807;
    for (ull k = 0, l = n / 2; k < l; ++k)
    {
        if (k > 0)
            rem += t[n + 1 - 2 * k];
        ull ans = (n - 2 - k) * t[1] + (2 * k + 1) * t[2] + from3toN - rem;
        if (ans < min)
            min = ans;
    }

    printf("%llu", min);

    return 0;
}