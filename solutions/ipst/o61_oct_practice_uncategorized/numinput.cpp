#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;;
using pll = pair<ll, ll>;

// ===================================================

const int INF = 1e9;
// const ll INF = 1e18;

const int N = 1010;
const int MOD = 9901;

int arr[N];
int dp[N][N];
bool rest[N];

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    
    int k, m, n = 0;
    scanf("%d%d", &k, &m);
    for (int i = 1; i <= k; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; ++j)
            arr[++n] = i;
    }

    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        rest[x] = true;
    }

    if (!rest[n] || arr[n] == k)
        dp[n][k] = 1;
    for (int i = n-1; i >= 1; --i) {
        for (int j = k; j >= 1; --j) {
            if (!rest[i] || j == arr[i]) {
                dp[i][j] = (dp[i+1][j] + dp[i+1][j+1]) % MOD;
            }
        }
    }

    printf("%d", dp[1][1]);
    return 0;
}