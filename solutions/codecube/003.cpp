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

long long lcm(int a, int b)
{
    return (long long)a/gcd1(a, b) * b;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld\n", lcm(a, b));

    return 0;
}