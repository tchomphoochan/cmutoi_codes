/* 872 - Ordering */

#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define N 22

int n, deg[N] = {};
int ctoi[256] = {};
char itoc[N] = {};
bool used[N] = {};
vector<int> g[N];
vector<int> went;

bool topo()
{
    bool did = false;
    bool degm0 = false;
    for (int u = 1; u <= n; ++u) {
        if (deg[u] != 0)
            degm0 = true;
        if (used[u] || deg[u] != 0)
            continue;
        did = true;
        used[u] = true;
        went.push_back(u);
        for (auto v : g[u]) {
            --deg[v];
        }
        if (!topo())
            return false;
        for (auto v : g[u]) {
            ++deg[v];
        }
        went.pop_back();
        used[u] = false;
    }
    if (!did) {
        if (degm0)
            return false;
        for (auto u : went) {
            printf("%c", itoc[u]);
            if (u != went.back())
                printf(" ");
        }
        printf("\n");
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {

        std::fill(deg, deg+N, 0);
        std::fill(ctoi, ctoi+256, 0);
        std::fill(itoc, itoc+N, '\0');
        std::fill(used, used+N, false);
        for (int i = 0; i < N; ++i)
            g[i].clear();
        went.clear();

        scanf("  ");
        char vars[500];
        gets(vars);
        for (int i = 0; vars[i]; ++i) {
            if (i % 2 == 0) {
                int ix = (i/2)+1;
                itoc[ix] = vars[i];
                n = ix;
            }
        }
        std::sort(itoc+1, itoc+n+1);
        for (int i = 1; i <= n; ++i) {
            ctoi[itoc[i]] = i;
        }

        scanf(" ");
        gets(vars);
        int len = strlen(vars);
        for (int i = 0; i < len; i += 4) {
            int u = ctoi[vars[i]];
            int v = ctoi[vars[i+2]];
            g[u].push_back(v);
            ++deg[v];
        }

        if (!topo())
            printf("NO\n");
        if (T != 0)
            printf("\n");

    }
    return 0;
}