#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;;
using pll = pair<ll, ll>;

// ===================================================

//const int INF = 1e9;
const ll INF = 1e18;

const int N = 1010;

int arr[N][N];
ll dp[N][N][3];

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            ll noeat = max(dp[i][j+1][0], dp[i+1][j][0]);
            ll eat1 = max(dp[i][j+1][1], dp[i+1][j][1]) + arr[i][j];
            ll eat2 = max(dp[i][j+1][2], dp[i+1][j][2]) + arr[i][j];
            dp[i][j][0] = max(noeat, eat1);
            dp[i][j][1] = max(noeat, eat2);
            dp[i][j][2] = noeat;
        }
    }

    printf("%lld\n", dp[1][1][0]);
    return 0;
}