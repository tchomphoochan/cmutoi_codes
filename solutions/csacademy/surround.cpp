#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
int a[N][N], qs[N][N];

int sum(int x, int y1, int y2)
{
    return qs[x][y2] - qs[x][y1-1];
}

int search(int x1, int y1)
{
    int x2 = x1+1;
    int y2 = y1;
    if (a[x1][y1] != 0 || a[x2][y2] != 0)
        return 0;
    while (true) {
        ++y2;
        if (y2 > m)
            return 0;
        if (a[x1][y2] == 0 && a[x2][y2] == 0)
            break;
        if (a[x1][y2] != 0 || a[x2][y2] != 1)
            return 0;
    }
    while (true) {
        ++x2;
        if (x2 > n)
            return 0;
        if (sum(x2, y1, y2) == 0)
            break;
        if (sum(x2, y1+1, y2-1) != y2-y1-1
            || a[x2][y1] == 1 || a[x2][y2] == 1)
            return 0;
    }
    return (x2-x1-1)*(y2-y1-1);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
            qs[i][j] = qs[i][j-1] + a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans = max(ans, search(i,j));
        }
    }

    if (ans == 0)
        ans = -1;
    printf("%d\n", ans);
    return 0;
}
