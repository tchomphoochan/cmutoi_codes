#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5+10;
const int INF = 1e9;

vector<int> G[N];

int ans = -INF;
int val[N];
pii max1[N][4], max2[N][4];

void doMax(pii &mx1, pii &mx2, pii v)
{
    if (v > mx1) {
        mx2 = mx1;
        mx1 = v;
    } else if (v > mx2) {
        mx2 = v;
    }
}

void dfs(int u, int p)
{
    for (int i = 1; i <= 3; ++i)
        max1[u][i] = max2[u][i] = {-INF, 0};
    for (auto v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        doMax(max1[u][1], max2[u][1], {val[v], v});
        doMax(max1[u][2], max2[u][2], {max1[v][1].first, v});
        //doMax(max1[u][2], max2[u][2], {max2[v][1].first, v});
        doMax(max1[u][3], max2[u][3], {max1[v][2].first, v});
        //doMax(max1[u][3], max2[u][3], {max2[v][2].first, v});
        ans = max(ans, max1[v][3].first + val[u]);
    }
    for (int i = 1; i <= 3; ++i) {
        if (max1[u][i].second == max1[u][4-i].second)
            ans = max(ans, max1[u][i].first + max2[u][4-i].first);
        else
            ans = max(ans, max1[u][i].first + max1[u][4-i].first);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < 4; ++i)
        max1[0][i] = max2[0][i] = {-INF, 0};
    while (t--) {

        int n;
        scanf("%d", &n);
        ans = -INF;
        for (int i = 1; i <= n; ++i)
        G[i].clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &val[i]);
        }
        
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(1, 0);

        /*for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 3; ++j)
                printf("%d-%d/%d-%d\t", max1[i][j].first, max1[i][j].second, max2[i][j].first, max2[i][j].second);
            printf("\n");
        }*/

        if (ans < 0)
            ans = -1;

        printf("%d\n", ans);

    }

    return 0;
}