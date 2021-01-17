/**
 * toi11_observatory
 * 
 * aquablitz11 (2017)
 */

#include <cstdio>
#include <algorithm>

using namespace std;

#define N 2010
#define INF 1e17

typedef long long ll;

int n, m, k;
int A[N][N];
ll sqr[N][N];
ll tri[N][N];

ll solve()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sqr[i][j] = 0;
            tri[i][j] = 0;
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            sqr[i][j] = sqr[i+1][j] + sqr[i][j-1] - sqr[i+1][j-1] + A[i][j];
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            tri[i][j] = tri[i+1][j-1] + sqr[i+1][j] - sqr[i+1][j-1] + A[i][j];
        }
    }
    ll ans = -INF;
    for (int i = 1; i <= n-k+1; ++i) {
        for (int j = k; j <= m; ++j) {
            ll a = tri[i][j];
            ll b = i+k <= n && j-k >= 1 ? tri[i+k][j-k] : 0;
            ll c = i+k <= n ? sqr[i+k][j] : 0;
            ll d = i+k <= n && j-k >= 1 ? sqr[i+k][j-k] : 0;
            ll s = a-b-c+d;
            ans = max(ans, s);
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    ll ans = solve();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m/2; ++j) {
            swap(A[i][j], A[i][m-j+1]);
        }
    }

    ans = max(ans, solve());
    printf("%lld", ans);

    return 0;
}