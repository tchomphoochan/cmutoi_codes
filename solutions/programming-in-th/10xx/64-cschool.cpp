#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int N = 100;

int n, m;
char p[N][N];
int dp[N][N];
int val[N][N];
int d[N*N];

void fill(int i, int j, int v)
{
    if (i < 1 || i > n || j < 1 || j > m
    || p[i][j] != 'P' || val[i][j] != 0)
        return;
    val[i][j] = v;
    fill(i-1, j, v);
    fill(i+1, j, v);
    fill(i, j-1, v);
    fill(i, j+1, v);
}

int countDiff(int x1, int y1, int x2, int y2)
{
    int c = 0;
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            if (p[i][j] == 'P')
                d[c++] = val[i][j];
        }
    }
    sort(d, d+c);
    return unique(d, d+c)-d;
}

int main()
{
    scanf("%d%d", &m, &n);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        scanf(" ");
        for (int j = 1; j <= m; ++j) {
            scanf("%c", &p[i][j]);
            if (p[i][j] != 'T')
                ans = max(ans, (dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1));
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            fill(i, j, i*n+j);
        }
    }

    int ans2 = INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j] == ans)
                ans2 = min(ans2, countDiff(i-ans+1, j-ans+1, i, j));
        }
    }

    printf("%d %d", ans*ans, ans2);
    return 0;
}