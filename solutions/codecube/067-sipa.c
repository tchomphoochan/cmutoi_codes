#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[1001];
    gets(text);

    int n = strlen(text);
    char sipa[] = "sipa";

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool match = false;
        if (i < n - 3)
        {
            match = true;
            for (int j = 0; j < 4; j++)
            {
                if (tolower(text[i + j]) != sipa[j])
                    match = false;
            }
        }
        if (match)
        {
            printf("\"%c%c%c%c\"", text[i], text[i + 1], text[i + 2], text[i + 3]);
            count++;
            i += 3;
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n%d", count);
    return 0;
}