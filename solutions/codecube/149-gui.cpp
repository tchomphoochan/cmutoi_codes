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

#define INF 2e9
//#define INF 1e18

#define N 100010

vector<int> G[N];
int maxSub[N];

int getMaxSub(int u)
{
    if (maxSub[u])
        return maxSub[u];

    int mx = u;
    for (auto v : G[u]) {
        mx = max(mx, getMaxSub(v));
    }

    return maxSub[u] = mx;
}

vector<int> fillSeq;

void fillBall(int u)
{
    for (auto v : G[u]) {
        fillBall(v);
    }
    fillSeq.push_back(u);
}

int main()
{
    //ios::sync_with_stdio(false);
    int n, m;
    scanf("%d%d", &n, &m);
    int p = 0;
    for (int v = 1; v <= n; ++v) {
        int u;
        scanf("%d", &u);
        if (u == 0)
            p = v;
        else
            G[u].push_back(v);
    }

    getMaxSub(p);
    for (int u = 1; u <= n; ++u) {
        sort(G[u].begin(), G[u].end(), [&] (const int a, const int b) {
            return maxSub[a] < maxSub[b];
        });
    }

    fillSeq.push_back(0);
    fillBall(p);
    ll qs[N] = {};
    for (int i = 1; i <= n; ++i)
        qs[i] = qs[i-1] + fillSeq[i];
    
    int ix = 0;
    while (m--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int c;
            scanf("%d", &c);
            ix += c;
            printf("%d\n", fillSeq[ix]);
        } else if (op == 2) {
            int c;
            scanf("%d", &c);
            ix -= c;
        } else {
            printf("%lld\n", qs[ix]);
        }

    }

    return 0;
}