/**
 * toi12_key
 * 
 * aquablitz11 (2017)
 */

#include <cstdio>
#include <cstring>

#define N 2010

char s[N], t[N], p[N];
bool dp[N][N];

int main()
{
    scanf("%s %s", s, t);
    int n = strlen(s);
    int m = strlen(t);
    int k;
    scanf("%d", &k);
    while (k--) {
        scanf(" %s", p);
        dp[n][m] = true;
        for (int i = n-1; i >= 0; --i)
            dp[i][m] = p[i+m] == s[i] && dp[i+1][m];
        for (int j = m-1; j >= 0; --j)
            dp[n][j] = p[n+j] == t[j] && dp[n][j+1];
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                dp[i][j] = (s[i] == p[i+j] && dp[i+1][j])
                || (t[j] == p[i+j] && dp[i][j+1]);
            }
        }
        printf("%s\n", dp[0][0] ? "Yes" : "No");
    }

    return 0;
}
