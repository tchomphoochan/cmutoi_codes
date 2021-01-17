#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    char str[1001];
    char sub[1001];
    scanf(" ");
    gets(str);
    scanf(" ");
    gets(sub);

    int count = 0;
    for (int i = 0; i < n - m + 1; i++)
    {
        if (strncmp(str + i, sub, m) == 0)
            count++;
    }

    printf("%d", count);
    return 0;
}