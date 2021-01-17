/* 315 - Network */

#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

#define N 111

int n;
int g[N][N] = {};
int nowtime[N];
int lowtime[N];
int parent[N];
bool visited[N];
bool isarti[N];
int counter = 0;
int rootchild = 0;

void findArti(int u)
{
    visited[u] = true;
    lowtime[u] = nowtime[u] = ++counter;
    for (int v = 1; v <= n; ++v) {
        if (!g[u][v])
            continue;
        if (!visited[v]) {
            if (u == 1)
                ++rootchild;
            parent[v] = u;
            findArti(v);
            if (nowtime[u] <= lowtime[v])
                isarti[u] = true;
            lowtime[u] = std::min(lowtime[u], lowtime[v]);
        } else if (v != parent[u]) {
            lowtime[u] = std::min(lowtime[u], nowtime[v]);
        }
    }
    if (u == 1)
        isarti[u] = rootchild > 1;
}

int main()
{
    while (true) {

        scanf("%d", &n);
        if (n == 0)
            break;

        std::fill(nowtime, nowtime+N, 0);
        std::fill(lowtime, lowtime+N, 0);
        std::fill(parent, parent+N, 0);
        std::fill(visited, visited+N, false);
        std::fill(isarti, isarti+N, false);
        counter = 0;
        rootchild = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                g[i][j] = false;
        }
        
        while (true) {
            int u;
            scanf("%d", &u);
            if (u == 0)
                break;
            scanf(" ");
            char str[500];
            gets(str);
            char *tok = strtok(str, " ");
            while (tok != NULL) {
                int v = atoi(tok);
                g[u][v] = g[v][u] = true;
                tok = strtok(NULL, " ");
            }
        }

        findArti(1);
        int c = 0;
        for (int i = 1; i <= n; ++i) {
            if (isarti[i])
                ++c;
        }

        printf("%d\n", c);

    }
    return 0;
}