/**
 * toi11_candle
 * 
 * aquablitz11 (2017)
 */

#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

#define N 2010

int n, m;
char c[N][N];

void fill(int x, int y)
{
    queue<ii> go;
    go.push({x, y});
    while (!go.empty()) {
        int i = go.front().first;
        int j = go.front().second;
        go.pop();
        if (c[i][j] == '0')
            continue;
        c[i][j] = '0';
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                if ((di == 0 && dj == 0)
                || i+di < 0 || i+di >= n || j+dj < 0 || j+dj >= m
                || c[i+di][j+dj] == '0')
                    continue;
                go.push({i+di, j+dj});
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf(" %s", c[i]);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (c[i][j] == '1') {
                fill(i, j);
                ++cnt;
            }
        }
    }

    printf("%d", cnt);
    return 0;
}