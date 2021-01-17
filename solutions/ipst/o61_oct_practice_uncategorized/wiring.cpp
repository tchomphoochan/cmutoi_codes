#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int u[N], v[N];
vector<int> G[N];
int color[N];

bool dfs(int u)
{
    if (color[u] == 1) return false;
    if (color[u] == 2) return true;
    color[u] = 1;
    for (auto v : G[u]) {
        if (!dfs(v)) {
            color[u] = 2;
            color[v] = 2;
            return false;
        }
    }
    color[u] = 2;
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {

        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &u[i]);
            G[i+1].clear();
            color[i+1] = 0;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
            if (u[i] != 0 && v[i] != 0
            && u[i] != v[i]) {
                G[u[i]].push_back(v[i]);
            }
        }

        bool ans = true;
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0) {
                if (!dfs(i)) {
                    ans = false;
                    break;
                }
            }
        }

        if (ans) printf("YES\n");
        else printf("NO\n");

    }

    return 0;
}