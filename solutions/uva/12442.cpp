/* 12442 - Forwarding Emails */

#include <cstdio>
#include <vector>

using namespace std;

#define N 50010

int n, to[N];
bool vis[N], visi[N];
int dp[N];

vector<int> pre;

void findCycle(int u)
{
    if (vis[u])
        return;
    if (visi[u]) {
        int c = 0;
        for (auto it = pre.crbegin(); it != pre.crend(); ++it) {
            ++c;
            if (*it == u)
                break;
        }
        for (auto it = pre.crbegin(); it != pre.crend(); ++it) {
            dp[*it] = c;
            if (*it == u)
                break;
        }
        return;
    }
    visi[u] = true;
    pre.push_back(u);
    findCycle(to[u]);
    pre.pop_back();
    vis[u] = true;
}

int dfs(int u)
{
    if (dp[u] != 0)
        return dp[u];
    return dp[u] = dfs(to[u])+1;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {

        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            to[u] = v;
            vis[i] = false;
            visi[i] = false;
            dp[i] = 0;
        }

        for (int u = 1; u <= n; ++u) {
            if (!vis[u])
                findCycle(u);
        }

        int mx = 0;
        int ans = 0;
        for (int u = 1; u <= n; ++u) {
            int ret = dfs(u);
            if (ret > mx) {
                ans = u;
                mx = ret;
            }
        }

        printf("Case %d: %d\n", t, ans);

    }
    return 0;
}