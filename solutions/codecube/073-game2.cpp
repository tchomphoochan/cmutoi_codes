#include <cstdio>
#include <algorithm>

#define N 210
#define INF 2e9

int n, m;
int s[N][N], min[N][N], max[N][N];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &s[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        min[i][m+1] = INF;
        max[i][m+1] = -INF;
    }
    for (int j = 1; j <= m; ++j) {
        min[n+1][j] = INF;
        max[n+1][j] = -INF;
    }

    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            if (i == n && j == m)
                continue;
            min[i][j] = std::min(
                min[i+1][j], min[i][j+1]
            ) + s[i][j];
            max[i][j] = std::max(
                max[i+1][j], max[i][j+1]
            ) + s[i][j];
        }
    }

    printf("%d", max[1][1] - min[1][1]);
    return 0;
}