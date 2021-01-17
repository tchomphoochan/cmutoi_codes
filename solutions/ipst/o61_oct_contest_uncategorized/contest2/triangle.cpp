#include <bits/stdc++.h>

using namespace std;

const int N = 360;
const int MOD = 29947;

int x, y, z;
int dp[N][N][N], dp2[N][N];

int solve(int i, int j, int k)
{
    if (i == 0) return dp2[j][k]-1;
    if (j == 0) return dp2[i][k]-1;
    if (k == 0) return dp2[i][j]-1;

    int &ans = dp[i][j][k];
    if (ans != 0) return ans;

    ans = solve(i-1, j, k) + solve(i, j-1, k) + solve(i, j, k-1)
    - solve(i-1, j-1, k) - solve(i-1, j, k-1) - solve(i, j-1, k-1) + solve(i-1, j-1, k-1);

    ans += solve(i-1, j-1, k);
    ans += (dp2[i-1][k-1]) * (dp2[j][z-k-1]);

    return ans;
}

int main()
{
    scanf("%d%d%d", &x, &y, &z);
    --x; --y; --z;

    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            if (i == 0 || j == 0) dp2[i][j] = 1;
            else dp2[i][j] = (dp2[i-1][j] + dp2[i][j-1]) % MOD;
        }
    }

    for (int i = 0; i <= z; ++i) {
        for (int j = 0; j <= x; ++j) {
            for (int k = 0; k <= x; ++k) {
                printf("%d ", solve(j, k, i));
            }
            printf("\n");
        }
        printf("-----\n");
    }

    printf("%d", solve(x, y, z));

    return 0;
}