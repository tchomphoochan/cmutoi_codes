#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int nxt[N], parent[N], trace[N];

int head(int u)
{
    if (parent[u] == u) return u;
    return parent[u] = head(parent[u]);
}

void merge(int u, int v)
{
    if (head(u) == u) {
        nxt[u] = v;
        parent[u] = v;
    } else {
        nxt[head(v)] = nxt[u];
        parent[head(v)] = nxt[u];
        nxt[u] = v;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < n-1; ++i) {
        int v, u;
        scanf("%d%d", &v, &u);
        merge(u, v);
    }

    int m;
    for (int i = 1; i <= n; ++i) {
        if (nxt[i] == 0) m = i;
        trace[nxt[i]] = i;
    }

    stack<int> ans;
    for (int u = m; u != 0; u = trace[u]) {
        ans.push(u);
    }
    while (!ans.empty()) {
        printf("%d", ans.top());
        if (ans.size() != 1)
            printf(" ");
        ans.pop();
    }
    printf("\n");

    return 0;
}