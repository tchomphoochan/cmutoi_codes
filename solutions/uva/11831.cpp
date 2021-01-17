/* 11831 - Sticker Collector Robot */

#include <cstdio>

#define N 105

int main()
{
    while (true) {

        int n, m, k;
        char p[N][N];
        scanf("%d%d%d", &n, &m, &k);
        if (n == 0)
            break;

        int r, c, ori;
        for (int i = 1; i <= n; ++i) {
            scanf(" ");
            for (int j = 1; j <= m; ++j) {
                scanf("%c", &p[i][j]);
                if (p[i][j] == 'N' || p[i][j] == 'S'
                || p[i][j] == 'L' || p[i][j] == 'O') {
                    r = i;
                    c = j;
                    if (p[i][j] == 'N')
                        ori = 0;
                    else if (p[i][j] == 'L')
                        ori = 1;
                    else if (p[i][j] == 'S')
                        ori = 2;
                    else //if (p[i][j] == 'O')
                        ori = 3;
                    p[i][j] = '.';
                }
            }
        }

        int cnt = 0;
        scanf(" ");
        while (k--) {
            char cmd;
            scanf("%c", &cmd);
            if (cmd == 'D') {
                ori = (ori+1)%4;
            } else if (cmd == 'E') {
                ori = (ori-1+4)%4;
            } else {

                int nr = r, nc = c;
                if (ori == 0) {
                    nr = r-1;
                } else if (ori == 1) {
                    nc = c+1;
                } else if (ori == 2) {
                    nr = r+1;
                } else {
                    nc = c-1;
                }

                if (nr >= 1 && nr <= n && nc >= 1 && nc <= m
                && p[nr][nc] != '#') {
                    if (p[nr][nc] == '*') {
                        ++cnt;
                        p[nr][nc] = '.';
                    }
                    r = nr; c = nc;
                }

            }
        }

        printf("%d\n", cnt);

    }
    return 0;
}