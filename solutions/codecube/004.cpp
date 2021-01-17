#include <stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int A[100010];
int main()
{
    int n;
    scanf("%d", &n);
    int g = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        g = gcd(g, A[i]);
    }
    long long ans = 0;
    if (g != 0) {
        for (int i = 0; i < n; ++i)
            ans += A[i]/g;
    }
    printf("%lld\n", ans);

    return 0;
}