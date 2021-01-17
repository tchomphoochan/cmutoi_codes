#include <bits/stdc++.h>

using namespace std;

const int N = 200;
const int INF = 1e9;

int n, m;
int arr[N][N], start[N][N], target[N][N];

void traverse(int dist[N][N], int sx, int sy)
{
    queue<int> qx, qy, qd;
    qx.push(sx);
    qy.push(sy);
    qd.push(1);
    while (!qx.empty()) {
        int x = qx.front();
        int y = qy.front();
        int d = qd.front();
        qx.pop();
        qy.pop();
        qd.pop();
        if (x < 1 || x > n || y < 1 || y > m || dist[x][y] != 0)
            continue;
        dist[x][y] = d;
        if (arr[x][y] == 1) {
            qx.push(x-1); qy.push(y); qd.push(d+1);
            qx.push(x+1); qy.push(y); qd.push(d+1);
            qx.push(x); qy.push(y-1); qd.push(d+1);
            qx.push(x); qy.push(y+1); qd.push(d+1);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int sx, sy, tx, ty;
    scanf("%d%d%d%d", &sx, &sy, &tx, &ty);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            scanf("%d", &arr[i][j]);
    }
    if (arr[sx][sy] == 0 || arr[tx][ty] == 0)
        assert(false);

    int cnt = 0, best = INF;
    traverse(start, sx, sy);
    traverse(target, tx, ty);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (arr[i][j] == 0 && start[i][j] != 0 && target[i][j] != 0) {
                ++cnt;
                best = min(best, start[i][j]+target[i][j]-1);
            }
        }
    }

    if (start[tx][ty] != 0)
        best = min(best, start[tx][ty]);
    printf("%d\n%d\n", cnt, best);

    return 0;
}