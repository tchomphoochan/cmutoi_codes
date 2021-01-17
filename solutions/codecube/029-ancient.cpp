#include <cstdio>
#include <cmath>

int powMod(int a, int b, int m)
{
    int res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            res = (res*a) % m;
        b >>= 1;
        a = (a*a) % m;
    }
    return res;
}

int main()
{
    int n, x, m = 997;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        int mi1 = x&1 ? -1 : 1;
        int ans = (powMod(4, x, m) + 2 * mi1) % m;
        printf("%d ", ans);
    }
    return 0;
}