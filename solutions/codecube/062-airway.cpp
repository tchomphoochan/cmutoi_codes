#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const ll INF = 1e18;
const int N = 1010;
const int M = 10010;

int n, m, x, y;
vector<ii> G[N];
int du, dv, dt, dk;

vector<ll> getShortestPath(int s)
{
    vector<ll> dist(n+1, INF);
    vector<bool> visited(n+1, false);
    dist[s] = 0;
    auto cmp = [&] (int a, int b) {
        return dist[a] > dist[b];
    };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    q.push(s);

    while (!q.empty()) {
        int u = q.top();
        q.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto v : G[u]) {
            if (visited[v.first])
                continue;
            dist[v.first] = min(dist[v.first], dist[u]+v.second);
            q.push(v.first);
        }
    }
    return dist;
}

int main()
{
    scanf("%d%d%d%d%d%d%d%d", &n, &m, &x, &y, &du, &dv, &dt, &dk);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
    }

    vector<ll> s1 = getShortestPath(x);
    ll d = s1[y];
    if (s1[du] <= dk) {
        vector<ll> s2 = getShortestPath(dv);
        d = min(d, s1[du]+dt+s2[y]);
    }

    printf("%lld", d);
    return 0;
}