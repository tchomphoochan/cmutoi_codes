#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

vector<int> G[N];
int dp[N][3];

void solve(int u, int p)
{
    dp[u][1] = dp[u][2] = 1;
    int mxdiff = 0;
    for (auto v : G[u]) {
        if (v == p) continue;
        solve(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
        mxdiff = max(mxdiff, dp[v][2]-dp[v][0]);
        dp[u][2] += dp[v][0];
    }
    if (mxdiff > 0)
        dp[u][1] += mxdiff;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--) {

        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            for (int j = 0; j < 3; ++j)
                dp[i][j] = 0;
        }
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        solve(1, 0);
        printf("%d\n", max(dp[1][0], dp[1][1]));

    }

    return 0;
}