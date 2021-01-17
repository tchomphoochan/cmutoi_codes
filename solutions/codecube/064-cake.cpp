#include <cstdio>
#include <cmath>

#define N 30

int num[N];
int den[N];

long long gcd(long long u, long long v)
{
    while (v != 0)
    {
        long long r = u % v;
        u = v;
        v = r;
    }
    return u;
}

long long lcm(long long u, long long v)
{
    return (u / gcd(u, v)) * v;
}

int main()
{
    char x;
    int n;
    scanf("%d", &n);

    long long l = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d%c%d", &num[i], &x, &den[i]);
        long long g = gcd(num[i], den[i]);
        num[i] /= g;
        den[i] /= g;
        l = lcm(l, den[i]);
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += num[i] * (l / den[i]);
    }

    if (sum % l == 0)
        printf("%lld\n0", sum / l);
    else {
        long long u = ceil(sum / (double)l);
        long long v = l - (sum % l);
        long long g = gcd(v, l);
        printf("%lld\n%lld/%lld", u, v/g, l/g);
    }

    return 0;
}