#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 10;

int n;
int a[N][N];
int dp[N][1<<N][1<<N];

int solve(int x, int xs, int ys)
{
    int &ans = dp[x][xs][ys];
    if (ans != -INF)
        return ans;
    if (x == n) { // alice pick row
        if (xs == (1<<n)-1)
            return 0;
        ans = -INF;
        for (int i = 0; i < n; ++i) {
            if (!(xs&(1<<i)))
                ans = max(ans, solve(i, xs|(1<<i), ys));
        }
    } else { // bob pick column (on row x)
        ans = INF;
        for (int i = 0; i < n; ++i) {
            if (!(ys&(1<<i)))
                ans = min(ans, solve(n, xs, ys|(1<<i)) + a[x][i]);
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
        }
        for (int k = 0; k <= n; ++k) {
            for (int i = 0; i < (1<<n); ++i) {
                for (int j = 0; j < (1<<n); ++j)
                    dp[k][i][j] = -INF;
            }
        }
        printf("%d\n", solve(n, 0, 0));
    }

    return 0;
}