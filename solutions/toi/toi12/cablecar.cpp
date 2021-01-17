/**
 * toi12_cablecar
 * 
 * aquablitz11 (2017)
 */

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define N 2505
#define M 1000010

struct Edge {
    int u, v, w;
};

Edge g[M];

int parent[N];

int getRoot(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = getRoot(parent[x]);
}

void join(int x, int y)
{
    int px = getRoot(x);
    int py = getRoot(y);
    parent[px] = py;
}

int main()
{
    int n, m, s, d, p;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[i] = {u, v, w};
    }
    scanf("%d%d%d", &s, &d, &p);

    sort(g, g+m, [&] (Edge a, Edge b) {
        return a.w > b.w;
    });

    for (int i = 0; i < m; ++i) {

        if (getRoot(g[i].u) == getRoot(g[i].v))
            continue;
        
        join(g[i].u, g[i].v);
        if (getRoot(s) == getRoot(d)) {
            printf("%.0lf", ceil((double)p / (g[i].w - 1)));
            break;
        }

    }

    return 0;
}