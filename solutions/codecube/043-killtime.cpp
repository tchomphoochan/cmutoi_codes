#include <cstdio>
#include <vector>

using namespace std;

#define INF 2e9
#define T 2010
#define N 310

struct E {
    int b, c, w;
};

vector<E> G[N];
int dp[T][N];

int main()
{
    int n, m, k, u, v;
    scanf("%d%d%d%d%d", &n, &m, &k, &u, &v);

    for (int i = 0; i < m; ++i) {
        int a, b, c, w;
        scanf("%d%d%d%d", &a, &b, &c, &w);
        G[a].push_back({b, c, w});
        G[b].push_back({a, c, w});
    }

    for (int a = 1; a <= n; ++a) {
        if (a != v)
            dp[0][a] = -INF;    
    }

    for (int t = 1; t <= k; ++t) {
        for (int a = 1; a <= n; ++a) {
            int ans = dp[t-1][a];
            for (auto bd : G[a]) {
                int b = bd.b;
                int c = bd.c;
                int w = bd.w;
                if (t-w >= 0)
                    ans = std::max(ans, dp[t-w][b] + c);
            }
            dp[t][a] = ans;
        }
    }

    if (dp[k][u] <= -INF/2)
        printf("Impossible");
    else
        printf("%d", dp[k][u]);

    return 0;
}