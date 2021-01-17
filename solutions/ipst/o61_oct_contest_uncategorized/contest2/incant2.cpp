#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 10010;
const int M = 1<<7;

int p[M];
ll dp[N][M];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < (1<<m); ++i)
        scanf("%d", &p[i]);
    
    ll ans;
    for (int i = m-1; i < n; ++i) {
        ans = 0;
        for (int j = 0; j < (1<<m); ++j) {
            int sl = (j<<1)&((1<<m)-1);
            dp[i][sl] = max(dp[i][sl], dp[i-1][j]+p[sl]);
            dp[i][sl|1] = max(dp[i][sl|1], dp[i-1][j]+p[sl|1]);
        }
        for (int j = 0; j < (1<<m); ++j) {
            ans = max(ans, dp[i][j]);
        }
    }

    printf("%lld", ans);
    return 0;
}