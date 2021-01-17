/* 796 - Critical Links */

#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

#define N 5010

int n;
vector<int> g[N];
set<ii> bridge;
bool vis[N];
int parent[N];
int rootCount;
int counter;
int lowtime[N];
int nowtime[N];

void findBridge(int u)
{
    nowtime[u] = lowtime[u] = ++counter;
    vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v]) {
            if (u == 0)
                ++rootCount;
            parent[v] = u;
            findBridge(v);
            if (nowtime[u] < lowtime[v]) {
                if (u < v)
                    bridge.insert({u, v});
                else
                    bridge.insert({v, u});
            }
            lowtime[u] = std::min(lowtime[u], lowtime[v]);
        } else if (v != parent[u]) {
            lowtime[u] = std::min(lowtime[u], nowtime[v]);
        }
    }
}

int main()
{
    while (scanf("%d", &n) != EOF) {
        
        bridge.clear();
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            vis[i] = false;
            parent[i] = -1;
            lowtime[i] = 0;
            nowtime[i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            int u, m;
            char x;
            scanf("%d %c%d%c", &u, &x, &m, &x);
            for (int j = 0; j < m; ++j) {
                int v;
                scanf("%d", &v);
                g[u].push_back(v);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                rootCount = 0;
                parent[i] = -1;
                findBridge(i);
            }
        }

        printf("%d critical links\n", (int)bridge.size());
        for (auto b : bridge) {
            printf("%d - %d\n", b.first, b.second);
        }
        printf("\n");

    }

    return 0;
}