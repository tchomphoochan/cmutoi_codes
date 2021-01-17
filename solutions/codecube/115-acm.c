#include <stdio.h>

#define max(a, b) (a > b ? a : b)

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        char res[21];
        scanf(" ");
        gets(res);

        int type = 0;
        for (int j = 0; res[j]; j++)
        {
            if (res[j] == 'X')
                type = max(type, 3);
            else if (res[j] == 'T')
                type = max(type, 2);
            else if (res[j] == '-')
                type = max(type, 1);
        }

        printf("Case #%d: ", i);
        if (type == 0)
            printf("Yes");
        else if (type == 3)
            printf("No - Runtime error");
        else if (type == 2)
            printf("No - Time limit exceeded");
        else
            printf("No - Wrong answer");
        printf("\n");
    }

    return 0;
}