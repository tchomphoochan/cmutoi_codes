/**
 * toi11_place
 * 
 * aquablitz11 (2017)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 200010
#define M 1000010

struct Edge
{
    int u, v, w;
};

Edge edges[M];
int parent[N];

int root(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = root(parent[u]);
}

void connect(int u, int v)
{
    u = root(u);
    v = root(v);
    parent[u] = v;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)    
        parent[i] = i;

    for (int i = 0; i < m; ++i)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    
    sort(edges, edges+m, [&] (const Edge &a, const Edge &b) {
        return a.w > b.w;
    });

    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        if (root(edges[i].u) == root(edges[i].v))
            continue;
        connect(edges[i].u, edges[i].v);
        ans += edges[i].w-1;
    }

    printf("%lld", ans);

    return 0;
}