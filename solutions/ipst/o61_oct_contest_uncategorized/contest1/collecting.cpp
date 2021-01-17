#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e18;
const int N = 50010;
const int M = 120010;
const int L = 35;

vector<pii> G[N];
set<int> group[L];

int main()
{
    int n, m, l, s, t;
    scanf("%d%d%d%d%d", &n, &m, &l, &s, &t);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        group[x].insert(i);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
    }

    vector<ll> dist(n+1, INF);
    dist[s] = 0;
    for (int r = 0; r < l; ++r) { // round

        for (int i = 1; i <= n; ++i) { // reset dist
            if (group[r].count(i) == 0)
                dist[i] = INF;
        }

        auto cmp = [&] (int a, int b) {
            return dist[a] > dist[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 1; i <= n; ++i) { // reset dist
            if (dist[i] != INF)
                pq.push(i);
        }

        vector<bool> visited(n+1, false);
        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            for (auto v : G[u]) {
                if (visited[v.first]) continue;
                ll nd = dist[u] + v.second;
                if (nd < dist[v.first]) {
                    dist[v.first] = nd;
                    pq.push(v.first);
                }
            }
        }
        
    }

    if (dist[t] >= INF/10)
        printf("-1");
    else
        printf("%lld", dist[t]);

    return 0;
}