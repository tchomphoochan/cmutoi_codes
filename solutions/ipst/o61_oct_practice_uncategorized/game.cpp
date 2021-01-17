#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

vector<int> G[N], R[N];
set<int> S[N];
bool visited[N];
stack<int> order;
int part[N], cnt[N], indeg[N];
int minrank[N], cntrank[N];

void dfs(int u)
{
    if (visited[u]) return;
    visited[u] = true;
    for (auto v : G[u]) {
        dfs(v);
    }
    order.push(u);
}

void get_scc(int u, int g)
{
    visited[u] = true;
    part[u] = g;
    ++cnt[g];
    for (auto v : R[u]) {
        if (!visited[v]) {
            get_scc(v, g);
        } else if (part[v] != g) {
            if (S[part[v]].count(g) == 0) {
                S[part[v]].insert(g);
                ++indeg[g];
            }
        }
    }
}

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < p; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        R[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    fill(visited, visited+n, 0);

    int g = 0;
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        if (visited[u]) continue;
        get_scc(u, ++g);
    }

    /*for (int i = 0; i < n; ++i)
        printf("%d ", part[i]);
    printf("\n%d scc\n", g);
    for (int i = 1; i <= g; ++i) {
        printf("[%d]:", i);
        for (auto v : S[i])
            printf(" %d", v);
        printf("\n");
    }*/

    queue<int> togo;
    for (int u = 1; u <= g; ++u) {
        if (indeg[u] == 0)
            togo.push(u);
    }

    vector<int> topo;
    while (!togo.empty()) {
        int u = togo.front();
        togo.pop();
        topo.push_back(u);
        for (auto v : S[u]) {
            if (--indeg[v] == 0)
                togo.push(v);
        }
    }

    int mxrank = 0;
    for (auto u : topo) {
        int rank = minrank[u];
        mxrank = max(mxrank, rank);
        cntrank[rank] += cnt[u];
        for (auto v : S[u])
            minrank[v] = max(minrank[v], rank+1);
    }

    for (int i = 0; i <= mxrank; ++i)
        printf("%d ", cntrank[i]);

    return 0;
}