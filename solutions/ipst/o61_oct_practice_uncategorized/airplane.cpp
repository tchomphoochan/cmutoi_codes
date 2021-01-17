#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;;
using pll = pair<ll, ll>;

// ===================================================

const int INF = 1e9;
// const ll INF = 1e18;

const int N = 310;
pii plane[N];
int dp[N][N][N];

int solve(int i, int j, int k)
{
    if (i < k || j < i) return 0;
    int &ans = dp[i][j][k];
    if (ans != -INF) return ans;

    int x = lower_bound(plane+i, plane+j+1, (pii){plane[i].second, -INF})-1 - plane;

    ans = solve(i+1,j,k);
    if (plane[i].second <= plane[k].second)
        ans = max(ans, solve(i+1,x,i) + solve(x+1,j,k) + 1);

    return ans;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    
    int TCALL;
    scanf("%d", &TCALL);
    while (TCALL--) {
        
        int n;
        scanf("%d", &n);
        plane[0] = {-INF, INF};
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &plane[i].first, &plane[i].second);
        sort(plane+1, plane+n+1, [&] (pii a, pii b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });
        for (int k = 0; k <= n; ++k) {
            for (int i = k; i <= n; ++i) {
                for (int j = i; j <= n; ++j)
                    dp[i][j][k] = -INF;
            }
        }
        
        printf("%d\n", solve(1, n, 0));
    }
    
    return 0;
}