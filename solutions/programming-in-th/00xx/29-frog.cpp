#include <stdio.h>
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    int cnt = 0;
    while (y >= 2*x) {
        y -= x;
        ++cnt;
    }
    if (x == y) ++cnt;
    else cnt += 2;
    printf("%d\n", cnt);
    return 0;
}