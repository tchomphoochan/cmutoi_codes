#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define N 500010

vector<int> G[N];
int parent[N];
bool visited[N];
bool cycle[N];

int countRemoved(int s, int f, bool nocycle)
{
    int sum = 0;
    stack<int> nxt;
    nxt.push(s);
    while (!nxt.empty()) {
        int u = nxt.top();
        nxt.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        ++sum;
        for (auto v : G[u]) {
            if (v == f || visited[v] || (nocycle && cycle[v]))
                continue;
            nxt.push(v);
        }
    }
    return sum;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    stack<pii> nxt;
    nxt.push({1, -1});
    int start=-1, end;
    while (!nxt.empty() && start == -1) {
        int u, p;
        tie(u, p) = nxt.top();
        nxt.pop();
        visited[u] = true;
        parent[u] = p;
        for (auto v : G[u]) {
            if (v == p)
                continue;
            if (start == -1 && visited[v]) {
                start = u;
                end = v;
                break;
            }
            nxt.push({v, u});
        }
    }
    for (int u = start; u != parent[end]; u = parent[u])
        cycle[u] = true;

    fill(visited+1, visited+n+1, false);

    int mx = 0;
    int ix = 0;
    if (cycle[m]) {
        for (int u = 1; u <= n; ++u) {
            if (!cycle[u] || u == m)
                continue;
            int val = countRemoved(u, 0, true)-1;
            if (val > mx) {
                mx = val;
                ix = u;
            }
        }
    }

    for (auto v : G[m]) {
        if (cycle[m] && cycle[v])
            continue;
        int val = countRemoved(v, m, false)-1;
        if (val > mx || (val == mx && v < ix)) {
            mx = val;
            ix = v;
        }
    }

    if (mx == 0)
        ix = m == 1 ? 2 : 1;    
    printf("%d\n%d\n", ix, mx);
    return 0;
}