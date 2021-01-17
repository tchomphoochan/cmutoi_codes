#include <cstdio>
#include <cmath>

int main()
{
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        printf("%.0Lf\n", powl(2, n));
    }
    return 0;
}