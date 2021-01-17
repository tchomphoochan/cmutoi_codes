#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6;
const int N = 110;
const int M = 10010;

char let[N][M];
int dist[N][M];
int ans[M];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf(" %s", let[i]);

        bool has = false;
        for (int j = 0; j < m; ++j) {
            if (let[i][j] == '1')
                has = true;
            dist[i][j] = INF;
        }
        if (!has) {
            printf("-1");
            return 0;
        }

        int last = -INF;
        for (int j = 0; j < 2*m; ++j) {
            int k = j%m;
            if (let[i][k] == '1')
                last = j;
            dist[i][k] = min(dist[i][k], j-last);
        }

        last = INF;
        for (int j = 2*m; j >= 0; --j) {
            int k = j%m;
            if (let[i][k] == '1')
                last = j;
            dist[i][k] = min(dist[i][k], last-j);
        }

        for (int j = 0; j < m; ++j)
            ans[j] += dist[i][j];

    }

    int a = INF;
    for (int i = 0; i < m; ++i)
        a = min(a, ans[i]);
    printf("%d", a);

    return 0;
}