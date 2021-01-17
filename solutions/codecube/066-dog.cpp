#include <bits/stdc++.h>

using namespace std;

struct Data {
    int x, y, d;
};

const int N = 1010;

int num[N][N];
bool visited[N][N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    queue<Data> togo;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &num[i][j]);
            if (num[i][j] == 0)
                togo.push({i, j, 0});
        }
    }

    int cnt = 0;
    while (!togo.empty()) {

        auto dt = togo.front();
        togo.pop();
        if (visited[dt.x][dt.y])
            continue;
        ++cnt;
        visited[dt.x][dt.y] = true;

        Data nxtlist[] = {
            {dt.x-1, dt.y, dt.d+1},
            {dt.x+1, dt.y, dt.d+1},
            {dt.x, dt.y-1, dt.d+1},
            {dt.x, dt.y+1, dt.d+1}
        };
        for (auto nxt : nxtlist) {
            if (nxt.x < 1 || nxt.x > n || nxt.y < 1 || nxt.y > m
            || visited[nxt.x][nxt.y] || nxt.d >= num[nxt.x][nxt.y])
                continue;
            togo.push(nxt);
        }

    }

    printf("%d\n", n*m-cnt);
    return 0;
}