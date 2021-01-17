/**
 * toi15_cave
 * 
 * aquablitz11 (2020)
 * 100/100
 * It is unclear whether this optimization actually works asymptotically.
 * I just copied the idea from some other people's solutions.
 */

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;
using pli = pair<ll, int>;
using plii = pair<ll, pii>;

const int N = 2010;
const ll INF = 1e18;

int n, s, t, m;
vector<pii> G[N];

int main()
{
    scanf("%d%d%d%d", &n, &s, &t, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, w; // 0-index
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
    }

    vector<vector<pli>> dist(n);
    priority_queue<plii, vector<plii>, greater<plii>> Q;
    dist[s].push_back({0, 0});
    Q.push({0, {s, 0}});
    while (!Q.empty()) {
        ll td = Q.top().first;
        int u, l;
        tie(u, l) = Q.top().second;
        Q.pop();
        for (auto v : G[u]) {
            ll nd = td + v.second;
            ll nl = l+1;
            bool ok = true;
            for (auto d : dist[v.first]) {
                if (nd > d.first && nl > d.second) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                dist[v.first].push_back({nd, nl});
                Q.push({nd, {v.first, nl}});
            }
        }
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int h;
        scanf("%d", &h);
        ll ans = INF;
        for (auto d : dist[t])
            ans = min(ans, d.first + (ll)(d.second-1)*h);
        printf("%lld ", ans);
    }
    
    return 0;
}