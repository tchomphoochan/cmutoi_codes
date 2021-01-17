#include <stdio.h>
#include <stdbool.h>

int m, n, t;
int board[101][41] = {};
int way[101] = {};
int count = 0;

#define bound(l) (l >= 1 && l <= m)
bool dfs(int time, int lane)
{
    if (time == t)
        return true;

    if (bound(lane - 1) && board[time + 1][lane - 1] == 0)
    {
        way[count++] = 1;
        if (dfs(time + 1, lane - 1))
            return true;
        else
            count--;
    }

    if (bound(lane + 1) && board[time + 1][lane + 1] == 0)
    {
        way[count++] = 2;
        if (dfs(time + 1, lane + 1))
            return true;
        else
            count--;
    }

    if (board[time + 1][lane] == 0)
    {
        way[count++] = 3;
        if (dfs(time + 1, lane))
            return true;
        else
            count--;
    }

    return false;
}

int main(void)
{
    scanf("%d%d%d", &m, &n, &t);
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= m; j++)
            scanf("%d", &board[i][j]);
    }

    dfs(0, n);
    for (int i = 0; i < count; i++)
        printf("%d\n", way[i]);

    return 0;
}