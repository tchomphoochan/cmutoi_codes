#include <bits/stdc++.h> // <- include everything
using namespace std;

using pii = pair<int, int>;

const int N = 10010;
const int INF = 1e9+1;

int n, m;
vector<pii> G[N];

vector<int> dijk(int s)
{
    vector<int> dist(n, INF);
    vector<bool> vis(n, false);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({dist[s], s});
    while (!Q.empty()) {
        int d, u;
        tie(d, u) = Q.top();
        Q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto vw : G[u]) {
            int v, w;
            tie(v, w) = vw;
            if (!vis[v] && dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                Q.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int s, t, p;
    scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<int> distS = dijk(s), distT = dijk(t);

    int rem = INF, num, used;
    for (int i = 0; i < n; ++i) {
        if (distS[i] <= p) {
            if (distT[i] < rem) {
                rem = distT[i];
                num = i;
                used = distS[i];
            } else if (distT[i] == rem && i < num) {
                num = i;
                used = distS[i];
            }
        }
    }

    printf("%d %d %d\n", num, used, rem);
    return 0;
}