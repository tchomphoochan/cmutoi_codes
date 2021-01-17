#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 300010;

vector<int> nodes, G[N];
int parent[N];
bool visited[N], cycle[N];

int main()
{
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        nodes.push_back(u);
        nodes.push_back(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    sort(nodes.begin(), nodes.end());
    nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());

    for (auto s : nodes) {
        if (visited[s])
            continue;
        stack<pii> nxt;
        nxt.push({s, -1});
        int start=-1, end;
        while (!nxt.empty()) {
            int u, p;
            tie(u, p) = nxt.top();
            nxt.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            parent[u] = p;
            for (auto v : G[u]) {
                if (v == p)
                    continue;
                if (start == -1 && visited[v]) {
                    start = u;
                    end = v;
                }
                nxt.push({v, u});
            }
        }
        for (int u = start; u != parent[end]; u = parent[u])
            cycle[u] = true;
    }

    for (auto s : nodes) {
        if (!cycle[s])
            continue;
        int ans = 0;
        stack<pii> nxt;
        nxt.push({s, -1});
        while (!nxt.empty()) {
            int u, p;
            tie(u, p) = nxt.top();
            nxt.pop();
            ++ans;
            for (auto v : G[u]) {
                if (v != p && !cycle[v])
                    nxt.push({v, u});
            }
        }
        printf("%d %d\n", s, ans-1);
    }

    return 0;
}