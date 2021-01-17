#include <stdio.h>

int n;
int lim;

void bp(int d)
{
    for (int i = lim >> 1; i > 0; i >>= 1)
    {
        printf((i & d) == 0 ? "0" : "1");
    }
}

int main(void)
{
    scanf("%d", &n);
    lim = (1 << n);

    for (int i = 0; i < lim; i++)
    {
        for (int j = 1; j < lim; j <<= 1)
        {
            if ((j & i) != 0)
                continue;
            bp(i);
            printf(" ");
            bp(i + j);
            printf("\n");
        }
    }

    return 0;
}