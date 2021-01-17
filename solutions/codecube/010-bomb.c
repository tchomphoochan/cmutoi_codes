#include <stdio.h>
#include <stdbool.h>

#define max(a, b) (a > b ? a : b)

int main(void)
{
    int n, b;
    scanf("%d%d", &n, &b);

    bool deto[500001] = {};
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (deto[i])
            continue;
        count++;
        for (int j = i; j <= n; j += i)
            deto[j] = true;
    }

    printf("%d", max(0, count - b));

    return 0;
}