#include <cstdio>
#include <queue>

using namespace std;

const int N = 55;

char map[N][N];
bool watcan[N][N];
bool gocan[N][N];
bool watvis[N][N];
bool visited[N][N];
int water[N][N];

int sx, sy, tx, ty;

struct XYD
{
    int x, y, d;
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    queue<XYD> q;

    for (int i = 0; i < n; ++i) {
        scanf(" ");
        for (int j = 0; j < m; ++j) {
            scanf("%c", &map[i][j]);
            water[i][j] = 1e9;
            if (map[i][j] == '.') {
                watcan[i][j] = gocan[i][j] = true;
            } else if (map[i][j] == '*') {
                water[i][j] = 0;
                q.push({i, j, 0});
            } else if (map[i][j] == 'S') {
                watcan[i][j] = gocan[i][j] = true;
                sx = i, sy = j;
            } else if (map[i][j] == 'D') {
                gocan[i][j] = true;
                tx = i, ty = j;
            }
        }
    }

    while (!q.empty()) {
        auto dt = q.front();
        q.pop();
        int x = dt.x, y = dt.y, d = dt.d;
        if (watvis[x][y])
            continue;
        watvis[x][y] = true;
        water[x][y] = d;
        XYD nxt[] = {
            {x-1, y, d+1},
            {x+1, y, d+1},
            {x, y-1, d+1},
            {x, y+1, d+1}
        };
        for (auto nt : nxt) {
            if (nt.x < 0 || nt.x >= n || nt.y < 0 || nt.y >= m
            || watvis[nt.x][nt.y] || !watcan[nt.x][nt.y])
                continue;
            q.push(nt);
        }
    }

    q.push({sx, sy, 0});
    while (!q.empty()) {
        auto dt = q.front();
        q.pop();
        int x = dt.x, y = dt.y, d = dt.d;
        if (visited[x][y])
            continue;
        if (x == tx && y == ty) {
            printf("%d", d);
            return 0;
        }
        visited[x][y] = true;
        XYD nxt[] = {
            {x-1, y, d+1},
            {x+1, y, d+1},
            {x, y-1, d+1},
            {x, y+1, d+1}
        };
        for (auto nt : nxt) {
            if (nt.x < 0 || nt.x >= n || nt.y < 0 || nt.y >= m
            || visited[nt.x][nt.y] || !gocan[nt.x][nt.y]
            || nt.d >= water[nt.x][nt.y])
                continue;
            q.push(nt);
        }
    }

    printf("KAKTUS");
    return 0;
}