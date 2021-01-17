#include <stdio.h>

int oneBit(int i)
{
    return (i - (i & -i)) == 0;
}

int main(void)
{
    int q, n, k;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &n, &k);
        printf("%c\n", (n <= k || oneBit(n - k + 1)) ? 'B' : 'A');
    }
    return 0;
}