#include <cstdio>
#include <cmath>

#define N 100000

int ans[N+10];

int main()
{
    double l = 0;
    for (int i = 1; i <= N; ++i) {
        l += log10(i);
        ans[i] = floor(l)+1;
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }

    return 0;
}