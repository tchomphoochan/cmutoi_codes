#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1010;
const int M = 5010;

bool G[N][N];
ii e[M];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &e[i].first, &e[i].second);
        G[e[i].first][e[i].second] = true;
        G[e[i].second][e[i].first] = true;
    }

    ll ans = 0, cnt = 0;
    for (int i = 0; i < m; ++i) {
        int u = e[i].first;
        int v = e[i].second;
        cnt = 0;
        for (int w = 1; w <= n; ++w) {
            if (G[u][w] && G[v][w])
                ++cnt;
        }
        ans += cnt*(cnt-1)/2;
    }

    cnt = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            int a = e[i].first;
            int b = e[i].second;
            int c = e[j].first;
            int d = e[j].second;
            if (G[a][c] && G[a][d] && G[b][c] && G[b][d])
                ++cnt;
        }
    }
    printf("%lld", ans-cnt*5/3);

    return 0;
}