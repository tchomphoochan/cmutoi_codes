#include <bits/stdc++.h>

using namespace std;

const int N = 360;
const int MOD = 29947;

int dp[N][N];

int main()
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    --x; --y; --z;

    // subtask 2
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            if (i == 0 || j == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    printf("%d\n", dp[x][y]);

    return 0;
}