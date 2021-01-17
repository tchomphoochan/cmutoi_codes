#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;;
using pll = pair<ll, ll>;

// ===================================================

//const int INF = 1e9;
const ll INF = 1e18;

const int N = 10010;
const int M = 50010;
const int S = 55;

struct Edge {
    int v, w, s;
};

vector<Edge> G[N];
bool visited[N][S];
ll dist[N][S];

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    
    int n, m, s, l;
    scanf("%d%d%d%d", &n, &m, &s, &l);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w, 0});
    }
    for (int i = 0; i < s; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w, 1});
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= s; ++j)
            dist[i][j] = INF;
    }
    dist[1][0] = 0;
    auto cmp = [&] (pii a, pii b) {
        return dist[a.first][a.second] > dist[b.first][b.second];
    };

    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    pq.push({1, 0});
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        if (visited[u.first][u.second])
            continue;
        visited[u.first][u.second] = true;
        ll d = dist[u.first][u.second];
        if (u.first == n) {
            printf("%lld\n", d);
            break;
        }
        for (auto v : G[u.first]) {
            int x = u.second+v.s;
            if (visited[v.v][x] || x > l)
                continue;
            if (d+v.w < dist[v.v][x]) {
                dist[v.v][x] = d+v.w;
                pq.push({v.v, x});
            }
        }
    }
    
    return 0;
}