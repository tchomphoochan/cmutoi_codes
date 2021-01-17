#include <cstdio>
//#include <iostream>
//#include <iomanip>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF ((int)1e9)
#define LINF ((ll)1e18)

#define N 100010

struct iii
{
    int v;
    int d;
    int t;
};

int n, m, k, t;
vector<iii> G[N];

ll getShortest(int s)
{
    vector<ll> dist(n+1, LINF);
    vector<bool> used(n+1);
    dist[1] = 0;

    auto cmp = [&] (const int a, const int b) {
        return dist[a] > dist[b];
    };
    priority_queue<int, vector<int>, decltype(cmp)> togo(cmp);
    togo.push(1);

    while (!togo.empty()) {
        int u = togo.top();
        togo.pop();
        if (used[u])
            continue;
        if (u == n)
            break;
        used[u] = true;
        for (auto e : G[u]) {
            if (used[e.v] || e.d > s)
                continue;
            dist[e.v] = min(dist[e.v], dist[u] + e.t);
            togo.push(e.v);
        }
    }

    return dist[n];
}

int btmn[N];

int main()
{
    //ios::sync_with_stdio(false);

    scanf("%d%d%d%d", &n, &m, &k, &t);
    for (int i = 1; i <= m; ++i) {
        int u, v, dn, ti;
        scanf("%d%d%d%d", &u, &v, &dn, &ti);
        G[u].push_back({v, dn, ti});
        G[v].push_back({u, dn, ti});
    }

    ll ans = LINF;
    vector<ii> boots(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &boots[i].first, &boots[i].second);
    }
    sort(boots.begin(), boots.end(), [&] (const ii a, const ii b) {
        return a.second < b.second;
    });

    btmn[k] = INF;
    for (int i = k-1; i >= 0; --i)
        btmn[i] = min(btmn[i+1], boots[i].first);
    
    if (getShortest(boots[k-1].second) > t) {
        printf("-1");
        return 0;
    }

    int left = 0;
    int right = k-1;
    while (left < right) {
        int mid = (left+right)/2;
        if (getShortest(boots[mid].second) > t)
            left = mid+1;
        else
            right = mid;
    }

    printf("%d", btmn[right]);
    return 0;
}