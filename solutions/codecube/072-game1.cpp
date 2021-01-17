#include <cstdio>
#include <algorithm>

#define N 510

bool can[N][N];
bool has[N][N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            int x;
            scanf("%d", &x);
            can[i][j] = (x == 0);
        }
    }

    int mx = n+m;
    has[0][0] = true;
    long long ans = 0;
    for (int t = 0; t <= mx; ++t) {
        int c = 0;
        for (int i = 0; i <= t; ++i) {
            int j = t-i;
            if (i >= n || j < 0 || j >= m || !has[i][j] || !can[i][j])
                continue;
            ++c;
            has[i+1][j] = has[i][j+1] = true;
        }
        ans += c*c;
    }

    printf("%lld", ans);
    return 0;
}