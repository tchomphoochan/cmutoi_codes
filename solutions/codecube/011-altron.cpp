#include <cstdio>
#include <algorithm>

#define INF 2e9
#define N 1010

int has[N][N];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &has[i][j]);
        }
    }

    int emp = 0;
    for (int i = n; i >= 1; --i) {
        int s = 0, dmp = 0;
        for (int j = 1; j < k; ++j) {
            if (has[i][j]) {
                ++s;
                ++dmp;
            }
        }
        int mn = INF;
        for (int j = k; j <= m; ++j) {
            dmp += has[i][j];
            s = s + has[i][j] - has[i][j-k];
            mn = std::min(mn, s);
        }

        if (mn <= emp) {
            printf("%d", i);
            break;
        }

        emp += m-dmp;
    }

    return 0;
}