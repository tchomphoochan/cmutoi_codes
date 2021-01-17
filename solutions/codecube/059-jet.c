#include <stdio.h>

int main(void)
{
    int m, n;
    scanf("%d%d", &m, &n);

    int c = -1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c = (c + 1) % 26;
            printf("%c", c +'A');
        }
        printf("\n");
    }

    return 0;
}