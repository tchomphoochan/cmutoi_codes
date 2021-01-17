#include <stdio.h>

void printn(char c, int n)
{
    for (int i = 0; i < n; i++)
        printf("%c", c);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n / 2; i++)
    {
        int dash = (n / 2) - i;
        printn('-', dash);
        printn('*', 2 * i + 1);
        printn('-', dash);
        printf("\n");
    }
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int dash = (n / 2) - i;
        printn('-', dash);
        printn('*', 2 * i + 1);
        printn('-', dash);
        printf("\n");
    }

    return 0;
}