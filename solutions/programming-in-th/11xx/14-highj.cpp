#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 310;
const int INF = 1e9;

int w[N*2][N*2];
int dp[N*2];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 2*n; ++i) {
        for (int j = 1; j <= 2*n; ++j) {
            scanf("%d", &w[i][j]);
        }
    }

    for (int i = 3; i <= 2*n; ++i) {
        dp[i] = INF;
        for (int j = 2; j < i; ++j)
            dp[i] = min(dp[i], w[i][j]+dp[j]);
    }

    printf("%d", dp[2*n]);
    return 0;
}