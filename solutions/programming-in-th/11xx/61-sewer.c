#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int r;
    int c;
    int t;
    char f;
} Point;

int time[102][102] = {};
bool up[102][102] = {};
bool down[102][102] = {};
bool left[102][102] = {};
bool right[102][102] = {};

Point queue[100000];
int front = -1;
int back = 0;

bool empty()
{
    return (front + 1 == back);
}

Point dequeue()
{
    return queue[++front];
}

void enqueue(Point en)
{
    queue[back++] = en;
}

int main(void)
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char type;
            scanf(" %c", &type);

            if (type == 'B' || type == 'D')
            {
                down[i][j] = true;
                if (i + 1 <= m)
                    up[i + 1][j] = true;
            }
            if (type == 'B' || type == 'R')
            {
                right[i][j] = true;
                if (j + 1 <= n)
                    left[i][j + 1] = true;
            }
        }
    }
    
    Point first = { 1, 1, 1, '\0' };
    enqueue(first);
    time[1][1] = 1;
    
    int ansT, ansR, ansC;
    while (!empty())
    {
        Point now = dequeue();
        if (left[now.r][now.c] && now.f != 'l')
        {
            if (time[now.r][now.c - 1] == now.t + 1)
            {
                ansT = now.t + 1;
                ansR = now.r;
                ansC = now.c - 1;
                break;
            }
            Point add = { now.r, now.c - 1, now.t + 1, 'r' };
            enqueue(add);
            time[now.r][now.c - 1] = now.t + 1;
        }
        if (right[now.r][now.c] && now.f != 'r')
        {
            if (time[now.r][now.c + 1] == now.t + 1)
            {
                ansT = now.t + 1;
                ansR = now.r;
                ansC = now.c + 1;
                break;
            }
            Point add = { now.r, now.c + 1, now.t + 1, 'l' };
            enqueue(add);
            time[now.r][now.c + 1] = now.t + 1;
        }
        if (up[now.r][now.c] && now.f != 'u')
        {
            if (time[now.r - 1][now.c] == now.t + 1)
            {
                ansT = now.t + 1;
                ansR = now.r - 1;
                ansC = now.c;
                break;
            }
            Point add = { now.r - 1, now.c, now.t + 1, 'd' };
            enqueue(add);
            time[now.r - 1][now.c] = now.t + 1;
        }
        if (down[now.r][now.c] && now.f != 'd')
        {
            if (time[now.r + 1][now.c] == now.t + 1)
            {
                ansT = now.t + 1;
                ansR = now.r + 1;
                ansC = now.c;
                break;
            }
            Point add = { now.r + 1, now.c, now.t + 1, 'u' };
            enqueue(add);
            time[now.r + 1][now.c] = now.t + 1;
        }
    }

    printf("%d\n%d %d", ansT, ansR, ansC);

    return 0;
}