#include <stdio.h>

int main()
{
    int x, y, k;
    scanf("%d%d%d", &x, &y, &k);
    
    int sum = 0;
    for (int a = x; a <= y; ++a) {
        sum += a/5 + a/25 + a/125 + a/625 + a/3125 + a/15625 + a/78125 + a/390625 + a/1953125 + a/9765625 + a/48828125 + a/244140625 + a/1220703125;
        sum %= k;
    }
    
    printf("%d", sum);
}