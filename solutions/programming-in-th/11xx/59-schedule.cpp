#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int N = 1010, M = 610;
int A[N], B[N];
int dp[N][N], mn[N][N];

inline void change(int &a, int &b, int na, int nb)
{
    if (na < a || (na == a && nb < b)) {
        a = na;
        b = nb;
    }
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &B[i]);
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = INF;
            mn[i][j] = INF;
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                mn[i][j] = 0;
            }
            if (i > 0) {
                if (mn[i-1][j]+A[i] <= m)
                    change(dp[i][j], mn[i][j], dp[i-1][j], mn[i-1][j]+A[i]);
                else
                    change(dp[i][j], mn[i][j], dp[i-1][j]+1, A[i]);
            }
            if (j > 0) {
                if (mn[i][j-1]+B[j] <= m)
                    change(dp[i][j], mn[i][j], dp[i][j-1], mn[i][j-1]+B[j]);
                else
                    change(dp[i][j], mn[i][j], dp[i][j-1]+1, B[j]);
            }
        }
    }

    printf("%d\n%d", dp[n][n], mn[n][n]);
    return 0;
}