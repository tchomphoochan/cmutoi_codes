#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 70;

map<int, ll> dp[2][N];

int main()
{
    int n;
    ll k;
    scanf("%d%lld", &n, &k);

    printf("ok 1\n");

    dp[1][2*n][0] = 1;
    for (int i = (2*n)-1; i >= 0; --i) {
        for (int j = -2*n; j <= 2*n; ++j)
            dp[1][i][j] = dp[1][i+1][j-1] + dp[1][i+1][j+1];
        dp[0][i][-1] = dp[1][i][-1];
    };

    printf("ok 2\n");

    for (int i = (2*n)-1; i >= 0; --i) {
        for (int j = 0; j <= 2*n; ++j)
            dp[0][i][j] = dp[0][i+1][j-1] + dp[0][i+1][j+1];
    }

    printf("ok 3\n");

    int i = 0, j = 0, s = 0;
    while (i != 2*n) {
        if (k <= dp[s][i+1][j+1]) {
            printf("(");
            ++i; ++j;
        } else {
            printf(")");
            k -= dp[s][i+1][j+1];
            ++i; --j;
        }
        if (s == 0 && j == -1)
            s = 1;
    }
    printf("\n");

    return 0;
}
