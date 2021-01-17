/* 11094 - Continents */

#include <cstdio>
#include <algorithm>

#define N 22

int m, n;
char land;
char st[N][N];

int fill(int r, int c)
{
    c = (c+n)%n;
    if (r < 0 || r >= m || c < 0 || c >= n)
        return 0;
    if (st[r][c] != land)
        return 0;
    st[r][c] = '\0';
    return fill(r-1, c) + fill(r, c+1) + fill(r+1, c) + fill(r, c-1) + 1;
}

int main()
{
    while (scanf("%d%d", &m, &n) != EOF)
    {
        for (int i = 0; i < m; ++i) {
            scanf(" ");
            for (int j = 0; j < n; ++j)
                scanf("%c", &st[i][j]);
        }
        int r, c;
        scanf("%d%d", &r, &c);
        land = st[r][c];
        fill(r, c);
        int mx = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mx = std::max(mx, fill(i, j));
            }
        }

        printf("%d\n", mx);
    }

    return 0;
}