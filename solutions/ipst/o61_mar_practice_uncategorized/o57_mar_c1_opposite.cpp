#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using piii = pair<pii, int>;
using pi5 = pair<pair<pii, pii>, int>;

#define X first
#define Y second

const int INF = 1e9;
const int N = 35;

int n, m;
pii ans(INF, INF);
char board[N][N];
int dist[N][N][N][N];
bool visited[N][N][N][N];

bool check(int x, int y)
{
    return !(x < 1 || x > n || y < 1 || y > m || board[x][y] == '#');
}

void sssp(int i, int j, int dist[N][N])
{
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y)
            dist[x][y] = INF;
    }

    queue<piii> q;
    q.push({pii(i, j), 0});
    while (!q.empty()) {
        int x, y, d;
        tie(x, y) = q.front().first;
        d = q.front().second;
        q.pop();
        if (!check(x, y) || dist[x][y] != INF)
            continue;
        dist[x][y] = d;
        q.push({pii(x-1, y), d+1});
        q.push({pii(x+1, y), d+1});
        q.push({pii(x, y-1), d+1});
        q.push({pii(x, y+1), d+1});
    }
}

pair<pii, pii> moveto(int x1, int y1, int x2, int y2, int dx, int dy)
{
    if (check(x1+dx, y1+dy))
        x1 += dx, y1 += dy;
    if (check(x2-dx, y2-dy))
        x2 -= dx, y2 -= dy;
    return {{x1, y1}, {x2, y2}};
}

int main()
{
    scanf("%d%d", &m, &n);
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; ++i) {
        scanf(" %s", &board[i][1]);
        for (int j = 1; j <= m; ++j) {
            // find starting position
            if (board[i][j] == 'A')
                x1 = i, y1 = j;
            else if (board[i][j] == 'B')
                x2 = i, y2 = j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sssp(i, j, dist[i][j]);
            /*printf("starting at %d %d\n", i, j);
            for (int x = 1; x <= n; ++x) {
                for (int y = 1; y <= m; ++y) {
                    if (dist[i][j][x][y] == INF)
                        printf("# ");
                    else
                        printf("%d ", dist[i][j][x][y]);
                }
                printf("\n");
            }*/
        }
    }

    queue<pi5> q;
    q.push({{pii(x1, y1), pii(x2, y2)}, 0});
    while (!q.empty()) {
        pii p1, p2;
        tie(p1, p2) = q.front().X;
        int d = q.front().Y;
        q.pop();
        if (visited[p1.X][p1.Y][p2.X][p2.Y])
            continue;
        visited[p1.X][p1.Y][p2.X][p2.Y] = true;
        ans = min(ans, {dist[p1.X][p1.Y][p2.X][p2.Y], d});
        pii n1, n2;
        tie(n1, n2) = moveto(p1.X, p1.Y, p2.X, p2.Y, 1, 0);
        q.push({{n1, n2}, d+1});
        tie(n1, n2) = moveto(p1.X, p1.Y, p2.X, p2.Y, -1, 0);
        q.push({{n1, n2}, d+1});
        tie(n1, n2) = moveto(p1.X, p1.Y, p2.X, p2.Y, 0, 1);
        q.push({{n1, n2}, d+1});
        tie(n1, n2) = moveto(p1.X, p1.Y, p2.X, p2.Y, 0, -1);
        q.push({{n1, n2}, d+1});
    }

    if (ans.X == INF)
        ans.X = -1, ans.Y = 0;
    printf("%d %d\n", ans.X, ans.Y);

    return 0;
}