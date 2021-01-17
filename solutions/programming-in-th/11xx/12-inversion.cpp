#include <cstdio>
#include <algorithm>

using namespace std;

const int MOD = 2012;
const int N = 10010;

int dp[N];
int ndp[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    dp[1] = 1;
    int c = 1;

    for (int i = 2; i <= n; ++i) {
        int nc = min(c+i-1, k+1);
        int s = 0;
        for (int j = 1; j <= nc; ++j) {
            int l = j-i;
            if (l < 0)
                l = 0;
            s = (s+dp[j]-dp[l]) % MOD;
            ndp[j] = s;
        }
        c = min(nc, k+1);
        copy(ndp+1, ndp+nc+1, dp+1);
    }

    printf("%d", dp[k+1]);
    return 0;
}