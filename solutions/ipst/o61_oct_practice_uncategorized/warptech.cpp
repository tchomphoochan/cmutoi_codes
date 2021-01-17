#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;;
using pll = pair<ll, ll>;

// ===================================================

const int INF = 1e9;
// const ll INF = 1e18;

const int N = 5010;
const int M = 100010;
const int Q = 5010;

struct Edge {
    int u, v, w;
};

pii query[Q];
Edge edges[M];
int parent[N];
int ans[N];

int root(int u)
{
    if (parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}

int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
        parent[i] = i;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges[i] = {u, v, w};
    }
    sort(edges, edges+m, [&] (Edge a, Edge b) {
        return a.w < b.w;
    });

    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        query[i] = {x, i};
    }
    sort(query, query+q, greater<pii>());

    int pnt = 0;
    int cluster = n;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;

        int up = root(u);
        int vp = root(v);
        if (up != vp) {
            parent[up] = vp;
            --cluster;
        }

        while (pnt < q && query[pnt].first >= cluster) {
            ans[query[pnt++].second] = w;
        }
    }

    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);
    
    return 0;
}