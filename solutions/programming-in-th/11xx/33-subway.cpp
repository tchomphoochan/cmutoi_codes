#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 1e6+10;
const int M = 510;

vector<int> ison[N];
int dist[M][M];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int s;
        scanf("%d", &s);
        for (int j = 0; j < s; ++j) {
            int u;
            scanf("%d", &u);
            ison[u].push_back(i);
        }
        for (int j = 1; j <= m; ++j)
            dist[i][j] = INF;
    }

    for (int i = 1; i <= n; ++i) {
        for (auto u : ison[i]) {
            for (auto v : ison[i])
                dist[u][v] = u == v ? 0 : 1;
        }
    }

    for (int k = 1; k <= m; ++k) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }

    int q;
    scanf("%d", &q);
    while (q--){
        int i, j;
        scanf("%d%d", &i, &j);
        int ans = INF;
        for (auto u : ison[i]) {
            for (auto v : ison[j]) {
                ans = min(ans, dist[u][v]);
                if (ans == 0) break;
            }
        }
        if (ans == INF)
            printf("impossible\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}