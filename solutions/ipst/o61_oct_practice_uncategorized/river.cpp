#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;;
using pll = pair<ll, ll>;

// ===================================================

const int INF = 1e9;
// const ll INF = 1e18;

const int MOD = 30011;
const int N = 50010;
const int K = 20;
const int L = 100010;

int A[N], B[N], C[N], D[N];
int dp[K][N], sum[K][N];
set<int> hfa[N], hfb[N];

int main()
{
    int n, m, k, l;
    scanf("%d%d%d%d", &n, &m, &k, &l);
    for (int i = 0; i < l; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        hfa[a].insert(b);
        hfb[b].insert(a);
    }

    // probably delete hfa/hfb edges that do not matter
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &A[i], &B[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &C[i], &D[i]);
    
    for (int i = 1; i <= m; ++i) {
        dp[0][i] = 1;    
        sum[0][i] = i % MOD;
    }
    int ans = 0;
    for (int t = 1; t <= k; ++t) {
        if (t & 1) {
            for (int i = 1; i <= n; ++i) {
                dp[t][i] = (sum[t-1][B[i]+A[i]-1] - sum[t-1][B[i]-1] + MOD) % MOD;
                int cnt = 0;
                for (auto b : hfa[i]) {
                    if (b >= B[i] && b < B[i]+A[i]) {
                        ++cnt;
                        dp[t][i] -= dp[t-1][b];
                        dp[t][i] = (dp[t][i] + MOD) % MOD;
                    }
                }
                for (int j = B[i]+A[i]; j <= m && cnt > 0; ++j) {
                    if (!hfa[i].count(j)) {
                        dp[t][i] += dp[t-1][j];
                        dp[t][i] %= MOD;
                        --cnt;
                    }
                }
                sum[t][i] = (sum[t][i-1] + dp[t][i]) % MOD;
                ans = (ans + dp[t][i]) % MOD;
            }
        } else {
            for (int i = 1; i <= m; ++i) {
                dp[t][i] = (sum[t-1][D[i]+C[i]-1] - sum[t-1][D[i]-1] + MOD) % MOD;
                int cnt = 0;
                for (auto a : hfb[i]) {
                    if (a >= D[i] && a < D[i]+C[i]) {
                        ++cnt;
                        dp[t][i] -= dp[t-1][a];
                        dp[t][i] = (dp[t][i] + MOD) % MOD;
                    }
                }
                for (int j = D[i]+C[i]; j <= n && cnt > 0; ++j) {
                    if (!hfb[i].count(j)) {
                        dp[t][i] += dp[t-1][j];
                        --cnt;
                    }
                }
                sum[t][i] = (sum[t][i-1] + dp[t][i]) % MOD;
            }
        }
    }

    printf("%d\n", ans % MOD);

    return 0;
}