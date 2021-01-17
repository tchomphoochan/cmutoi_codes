#include <stdio.h>
#include <stdlib.h>

// iterative style
int gcd1(int a, int b)
{
    while (b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return abs(a);
}

// recursive style
int gcd2(int a, int b)
{
    if (b == 0)
        return abs(a);
    return gcd2(b, a%b);
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", gcd1(a, b));

    return 0;
}