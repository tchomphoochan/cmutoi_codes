#include <cstdio>
#include <algorithm>

#define N 100010
#define K 110

int c[N], qs[N];
int dp[2*N], newdp[2*N];

int main()
{
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
        qs[i] = qs[i-1] + c[i];
    }
    
    for (int j = 1; j <= k; ++j) {
        for (int i = n; i >= 1; --i) {
            int nx = i+p-1;
            if (nx > n)
                nx = n;
            newdp[i] = std::max(
                newdp[i+1],
                dp[i+p] + qs[nx] - qs[i-1]
            );
        }
        for (int i = 1; i <= n; ++i) {
            dp[i] = newdp[i];
            newdp[i] = 0;
        }
    }

    printf("%d", dp[1]);
    return 0;
}