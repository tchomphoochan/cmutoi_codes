#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
const int INF = 1e9;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

int n, m;
char B[N][N];
int dist[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    queue<pii> Q;
    for (int i = 1; i <= n; ++i) {
        scanf(" %s", B[i]+1);
        for (int j = 1; j <= m; ++j) {
            dist[i][j] = INF;
            if (B[i][j] == 'X') {
                dist[i][j] = 0;
                Q.push({i, j});
            }
        }
    }

    ll cnt = 0, sum = 0;
    while (!Q.empty()) {
        pii u = Q.front();
        Q.pop();
        if (B[u.x][u.y] == 'A') {
            ++cnt;
            sum += dist[u.x][u.y];
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            pii v(u.x+dx[i], u.y+dy[i]);
            if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m && B[v.x][v.y] != 'W' && dist[v.x][v.y] == INF) {
                dist[v.x][v.y] = dist[u.x][u.y]+1;
                Q.push(v);
            }
        }
    }

    printf("%lld %lld\n", cnt, sum*2);
    
    return 0;
}