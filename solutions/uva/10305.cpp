/* 10305 - Ordering Tasks */

#include <cstdio>
#include <vector>

using namespace std;

#define N 110

int n, m;
vector<int> g[N], ans;
bool vi[N];

void dfs(int u)
{
    if (vi[u])
        return;
    vi[u] = true;
    for (auto v : g[u])
        dfs(v);
    ans.push_back(u);
}

int main()
{
    while (true)
    {
        scanf("%d%d", &n, &m);
        if (n == 0)
            break;
        std::fill(g, g+N, vector<int>());
        std::fill(vi, vi+N, false);
        ans.clear();
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
        }
        for (int i = 1; i <= n; ++i) {
            if (!vi[i])
                dfs(i);
        }
        for (int i = n-1; i >= 0; --i) {
            printf("%d", ans[i]);
            if (i != 0)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}