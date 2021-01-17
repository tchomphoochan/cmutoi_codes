#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    char c;
    scanf(" %c", &c);
    for (int i = 1; i < n; i++)
    {
        char d;
        scanf("%c", &d);
        if (d == c)
        {
            printf("Wrong Answer");
            return 0;
        }
        else
        {
            c = d;
        }
    }

    printf("Accepted");
    return 0;
}