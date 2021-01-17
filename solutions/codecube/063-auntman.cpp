#include <cstdio>

#define N 1010

int n, m;
char a[N][N];
bool b[N][N];

#define bound(r, c) (1 <= r && r <= n && 1 <= c && c <= m)

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf(" ");
        for (int j = 1; j <= m; ++j) {
            scanf("%c", &a[i][j]);
            if (a[i][j] == 'x') {
                b[i][j] = true;
                if (bound(i-1, j-1))
                    b[i-1][j-1] = true;
                if (bound(i-2, j-2))
                    b[i-2][j-2] = true;
                if (bound(i-1, j+1))
                    b[i-1][j+1] = true;
                if (bound(i-2, j+2))
                    b[i-2][j+2] = true;
                if (bound(i+1, j-1))
                    b[i+1][j-1] = true;
                if (bound(i+2, j-2))
                    b[i+2][j-2] = true;
                if (bound(i+1, j+1))
                    b[i+1][j+1] = true;
                if (bound(i+2, j+2))
                    b[i+2][j+2] = true;
            } else if (a[i][j] == '+') {
                b[i][j] = true;
                if (bound(i-1, j))
                    b[i-1][j] = true;    
                if (bound(i, j-1))
                    b[i][j-1] = true;    
                if (bound(i+1, j))
                    b[i+1][j] = true;    
                if (bound(i, j+1))
                    b[i][j+1] = true;    
            }
        }
    }

    int c = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (b[i][j])
                a[i][j] = '.';
            if (a[i][j] == 'A')
                ++c;
        }
    }

    printf("%d\n", c);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf("%c", a[i][j]);
        printf("\n");
    }

    return 0;
}