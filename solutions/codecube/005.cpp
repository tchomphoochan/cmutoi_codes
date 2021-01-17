#include <stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}
long long lcm(long long a, long long b) {
    return (long long)a/gcd(a, b) * b;
}

int main()
{
    int n;
    long long l, x;
    scanf("%d%lld", &n, &l);
    for (int i = 1; i < n; ++i) {
        scanf("%lld", &x);
        l = lcm(l, x);
    }
    printf("%lld\n", l);

    return 0;
}