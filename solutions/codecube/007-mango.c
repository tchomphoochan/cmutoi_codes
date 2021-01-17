#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *src = (char*) malloc(sizeof(char) * 1000001);
    char *dest = (char*) malloc(sizeof(char) * 1000001);
    char *out = (char*) malloc(sizeof(char) * 1000001);

    scanf("%s %s", src, dest);
    bool fail = false;

    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        char s = tolower(src[i]) - 'a';
        char d = tolower(dest[i]) - 'a';

        int dist = (s - d) % 26;
        if (dist < 0)
            dist += 26;

        if (dist >= 10)
        {
            fail = true;
            break;
        }

        out[i] = dist + '0';
    }
    out[i] = '\0';

    if (fail)
        printf("R.I.P.");
    else
        printf("%s", out);
    
    free(src);
    free(dest);
    free(out);
    return 0;
}