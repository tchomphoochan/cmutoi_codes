#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const ll INF = 1e18;
const int N = 100010;
const int K = 6;

vector<ii> G[N];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
    }

    vector<vector<ll> > dist(K, vector<ll>(n+1, INF));
    vector<vector<bool> > visited(K, vector<bool>(n+1, false));
    dist[0][1] = 0;

    auto cmp = [&] (ii a, ii b) {
        int d1 = dist[a.first][a.second];
        int d2 = dist[b.first][b.second];
        return d1 > d2 || (d1 == d2 && a.first > b.first);
    };
    priority_queue<ii, vector<ii>, decltype(cmp)> pq(cmp);
    pq.push({0, 1}); // k, node

    ll ans = INF;
    while (!pq.empty()) {
        ii u = pq.top();
        pq.pop();
        if (visited[u.first][u.second])
            continue;
        visited[u.first][u.second] = true;
        if (u.second == n)
            ans = min(ans, dist[u.first][u.second]);
        for (auto vw : G[u.second]) {
            int v = vw.first;
            int w = vw.second;
            if (w < -100) {
                if (u.first == k)
                    continue;
                if (visited[u.first+1][v])
                    continue;
                if (dist[u.first][u.second] < dist[u.first+1][v]) {
                    dist[u.first+1][v] = dist[u.first][u.second];
                    pq.push({u.first+1, v});
                }
            } else {
                if (visited[u.first][v])
                    continue;
                w = max(w, 0);
                int nd = dist[u.first][u.second] + w;
                if (nd < dist[u.first][v]) {
                    dist[u.first][v] = nd;
                    pq.push({u.first, v});
                }
            }
        }
    }
    if (ans >= INF)
        ans = -1;
    printf("%lld", ans);

    return 0;
}