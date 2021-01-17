#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int MOD = 2553;

int n;
char s[N];
int dp[3][3], ndp[3][3];

int gc(char c)
{
    if (c == 'P') return 0;
    if (c == 'R') return 1;
    if (c == 'S') return 2;
    return 3;
}

int main()
{
    scanf("%d %s", &n, s+1);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            dp[i][j] = 1;
    }

    int ans = 1;
    for (int i = n-1; i >= 1; --i) {

        bool end = false;
        for (int j = 0; j < 3 && !end; ++j) {
            if (i != 1 && j != gc(s[i]))
                continue;
            for (int k = 0; k < 3 && !end; ++k) {
                if (j == gc(s[i]) && k == gc(s[i+1])) {
                    end = true;    
                    break;
                }
                if (gc(s[i-1]) != gc(s[i]) || gc(s[i]) != k) {
                    ans += dp[j][k];
                    ans %= MOD;
                }
            }
        }

        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    if (j != k || k != l)
                        ndp[j][k] += dp[k][l];
                }
            }
        }
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[j][k] = ndp[j][k] % MOD;
                ndp[j][k] = 0;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}