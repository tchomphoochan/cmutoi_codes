#include <stdio.h>

#define max(a, b) (a > b ? a : b)

int main(void)
{
    int r, p, s;
    scanf("%d%d%d", &r, &p, &s);

    int m = max(r, max(p, s));
    if (r + p + s != 100)
        printf("BUG");
    else if ((r == m && p == m)
    || (r == m && s == m)
    || (p == m && s == m))
        printf("I DON'T KNOW");
    else if (r == m)
        printf("PAPER");
    else if (p == m)
        printf("SCISSORS");
    else
        printf("ROCK");
    
    return 0;
}