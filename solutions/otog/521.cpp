#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const ll INF = 1e18;
const int N = 80010;
const int L = 15;

int n, m, l, q;
vector<ii> G[N];
int room[L];
ll rdist[L][L];

vector<ll> sssp(int s)
{
    vector<ll> dist(n+1, INF);
    vector<bool> visited(n+1, false);
    dist[s] = 0;

    auto cmp = [&] (int a, int b) {
        return dist[a] > dist[b];
    };
    priority_queue<int, vector<int>, decltype(cmp)> togo(cmp);
    togo.push(s);

    while (!togo.empty()) {
        int u = togo.top();
        togo.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto v : G[u]) {
            if (!visited[v.first] && dist[u]+v.second < dist[v.first]) {
                dist[v.first] = dist[u]+v.second;
                togo.push(v.first);
            }
        }
    }

    return dist;
}

ll dp[L][L];

ll solve(int x, int e)
{
    if (e > q)
        return INF;
    ll &ans = dp[x][e];
    if (ans)
        return ans;
    ans = INF;

    int u = room[x];
    for (int y = 1; y <= l; ++y) {
        int v = room[y];
        if (u == v)
            continue;
        ans = min(ans, rdist[x][y]/(1<<e) + solve(y, e+1));
    }
    ans = min(ans, rdist[x][l+1]/(1<<e));

    return ans;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &l, &q);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
    }
    G[0].push_back({1, 0});

    room[0] = 0;
    for (int i = 1; i <= l; ++i) {
        scanf("%d", &room[i]);
        for (int j = 1; j < i; ++j) // test case fucked up lol
            assert(room[j] != room[i]);
    }
    room[l+1] = n;

    for (int i = 0; i <= l+1; ++i) {
        vector<ll> dist = sssp(room[i]);
        for (int j = 0; j <= l+1; ++j) {
            rdist[i][j] = dist[room[j]];
        }
    }

    ll ans = solve(0, 0);
    printf("%lld", ans);

    return 0;
}