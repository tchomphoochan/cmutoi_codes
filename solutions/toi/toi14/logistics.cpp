/**
 * toi14_logistics
 * 
 * aquablitz11 (2019)
 * 100/100
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int INF = 1e9;

using pii = pair<int, int>;
#define F first
#define S second
template<typename T> inline bool setmin(T &a, T b) { if (b < a) { a = b; return true; } return false; }

struct State {
    int d, u, f, b;
    bool operator<(const State &o) const {
        return d > o.d;
    }
};

int P[N], dist[N][N][2];
bool vis[N][N][2];
vector<pii> G[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &P[i]);
    int s, t, mf, m;
    scanf("%d%d%d%d", &s, &t, &mf, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= mf; ++j)
            dist[i][j][0] = dist[i][j][1] = INF;
    }
    dist[s][0][0] = 0;
    priority_queue<State> Q;
    Q.push({0, s, 0, 0});
    while (!Q.empty()) {
        int d = Q.top().d, u = Q.top().u, f = Q.top().f, b = Q.top().b;
        Q.pop();
        if (vis[u][f][b]) continue;
        vis[u][f][b] = true;
        if (u == t && f == mf) {
            printf("%d\n", d);
            break;
        }

        if (f != mf && !vis[u][f+1][b] && setmin(dist[u][f+1][b], d+P[u])) // add fuel
            Q.push({dist[u][f+1][b], u, f+1, b});
        if (b == 0 && !vis[u][mf][1] && setmin(dist[u][mf][1], d)) // use card to fully fill
            Q.push({dist[u][mf][1], u, mf, 1});
        for (auto v : G[u]) { // go to next city
            if (f-v.S >= 0 && !vis[v.F][f-v.S][b] && setmin(dist[v.F][f-v.S][b], d))
                Q.push({dist[v.F][f-v.S][b], v.F, f-v.S, b});
        }
    }
    
    return 0;
}