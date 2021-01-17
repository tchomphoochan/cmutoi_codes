/* 11953 - Battleships */

#include <cstdio>

#define N 110

int n;
char s[N][N];

bool fill(int r, int c)
{
    if (r < 1 || r > n || c < 1 || c > n)
        return false;
    if (s[r][c] == '.')
        return false;
    
    bool ans = s[r][c] == 'x';
    s[r][c] = '.';
    ans |= fill(r-1, c) | fill(r+1, c) | fill(r, c-1) | fill(r, c+1);
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {

        scanf("%d", &n);

        for (int i = 1; i <= n; ++i) {
            scanf(" ");
            for (int j = 1; j <= n; ++j)
                scanf("%c", &s[i][j]);
        }

        int count = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                count += fill(i, j) ? 1 : 0;
            }
        }

        printf("Case %d: %d\n", t, count);

    }
    return 0;
}