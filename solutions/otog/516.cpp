#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
const int N = 1010;

int n, ka, kb, kc;
int dp[N][4][2][2][2];

int solve(int day, int place, int a, int b, int c)
{
    if (day == n+1)
        return a && b && c ? 1 : 0;

    int &ans = dp[day][place][a][b][c];
    if (ans)
        return ans;
    
    if (place == 1) {
        for (int t = day+1; t <= day+ka && t <= n+1; ++t) {
            if (t == n+1) {
                ans += solve(n+1, 0, a, b, c);
                ans %= MOD;
            } else {
                ans += solve(t, 2, a, b|1, c);
                ans %= MOD;
                ans += solve(t, 3, a, b, c|1);
                ans %= MOD;
            }
        }
    } else if (place == 2) {
        for (int t = day+1; t <= day+kb && t <= n+1; ++t) {
            if (t == n+1) {
                ans += solve(n+1, 0, a, b, c);
                ans %= MOD;
            } else {
                ans += solve(t, 3, a, b, c|1);
                ans %= MOD;
            }
        }
    } else if (place == 3) {
        for (int t = day+1; t <= day+kc && t <= n+1; ++t) {
            if (t == n+1) {
                ans += solve(n+1, 0, a, b, c);
                ans %= MOD;
            } else {
                ans += solve(t, 1, a|1, b, c);
                ans %= MOD;
            }
        }
    }

    return ans;
}

int main()
{
    scanf("%d%d%d%d", &n, &ka, &kb, &kc);

    int ans = solve(1, 1, 1, 0, 0);
    printf("%d", ans);

    return 0;
}