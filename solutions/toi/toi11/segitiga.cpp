/**
 * toi11_segitiga
 * 
 * aquablitz11 (2017)
 */

#include <cstdio>

#define N 300

int main()
{
    for (int _ = 0; _ < 20; ++_) {

        int n;
        char s[N];
        bool can[N][N][3] = {};
        scanf("%d %s", &n, s);

        for (int i = 0; i < n; ++i)
            can[i][i][s[i]-'0'] = true;
        
        for (int z = 2; z <= n; ++z) {
            for (int i = 0; i <= n-z; ++i) {
                int j = i+z-1;
                for (int k = i; k < j; ++k) {
                    can[i][j][0] |= (can[i][k][0] && can[k+1][j][2]);
                    can[i][j][1] |= (can[i][k][0] && can[k+1][j][1])
                    || (can[i][k][1] && can[k+1][j][1])
                    || (can[i][k][1] && can[k+1][j][2])
                    || (can[i][k][2] && can[k+1][j][0])
                    || (can[i][k][2] && can[k+1][j][2]);
                    can[i][j][2] |= (can[i][k][0] && can[k+1][j][0])
                    || (can[i][k][1] && can[k+1][j][0])
                    || (can[i][k][2] && can[k+1][j][1]);
                }
            }
        }

        printf("%s\n", can[0][n-1][0] ? "yes" : "no");

    }
    return 0;
}