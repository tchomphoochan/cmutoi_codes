#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 20010;
const int INF = 1e9;

int R[N], P[N];
int dp[N], ndp[N];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    R[0] = 0;
    R[m+1] = n;
    for (int i = 1; i <= m; ++i)
        scanf("%d", &R[i]);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &P[i]);
    
    dp[k+1] = 0;
    for (int j = k; j >= 1; --j)
        dp[j] = -INF;
    for (int i = m; i >= 0; --i) {
        ndp[k+1] = -INF;
        for (int j = k; j >= 1; --j)
            ndp[j] = max(dp[j+1], dp[j]) + P[j]*(R[i+1]-R[i]);
        copy(ndp, ndp+k+1, dp);
    }

    printf("%d", dp[1]);
    return 0;
}