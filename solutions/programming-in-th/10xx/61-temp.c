#include <stdio.h>

int m;
int temp[20][20];

int max(int a, int b)
{
    return a > b ? a : b;
}

int depth(int r, int c)
{
    int res = temp[r][c];
    if (res == 100)
        return -5;
    #define bound(y, x) (x >= 0 && x < m && y >= 0 && y < m && temp[y][x] > temp[r][c])
    if (bound(r - 1, c))
        res = max(res, depth(r - 1, c));
    if (bound(r + 1, c))
        res = max(res, depth(r + 1, c));
    if (bound(r, c - 1))
        res = max(res, depth(r, c - 1));
    if (bound(r, c + 1))
        res = max(res, depth(r, c + 1));
    return res;
}

int main(void)
{
    int c, r;
    scanf("%d %d %d", &m, &c, &r);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d", &temp[i][j]);
    }

    printf("%d", depth(r - 1, c - 1));
}