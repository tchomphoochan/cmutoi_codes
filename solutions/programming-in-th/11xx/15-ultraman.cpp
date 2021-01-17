#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;
const ll INF = 1e17;

int ix[N];
ll x[N], y[N], dist[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", &x[i], &y[i]);
        ix[i] = i;
        dist[i] = INF;
    }

    dist[1] = 0;
    for (int i = 1; i < n; ++i) {
        int b = i+1;
        for (int j = i+1; j <= n; ++j) {
            ll dx = x[ix[j]] - x[ix[i]];
            ll dy = y[ix[j]] - y[ix[i]];
            ll nd = dx*dx + dy*dy;
            if (nd < dist[ix[j]])
                dist[ix[j]] = nd;
            if (dist[ix[j]] < dist[ix[b]])
                b = j;
        }
        swap(ix[i+1], ix[b]);
    }

    sort(dist+1, dist+n+1, greater<int>());
    printf("%lld\n", dist[k]);

    return 0;
}