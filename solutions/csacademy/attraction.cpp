#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

const int N = 3e5+1;
const int INF = 1e9;
const pii PINF = {-INF, 0};

vector<int> G[N];
int b[N];
pii up[N][2];

inline bool comp(const pii &a, const pii &b)
{
    if (a.first != b.first)
        return a.first > b.first;
    else
        return a.second < b.second;
}
inline void max2(pii &a, pii &b, const pii &x)
{
    if (comp(x, a)) {
        if (a.second != x.second)
            b = a;
        a = x;
    } else if (comp(x, b)) {
        if (a.second != x.second)
            b = x;
    }
}

void dfs(int u, int p)
{
    up[u][0] = up[u][1] = PINF;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            max2(up[u][0], up[u][1], {up[v][0].first-1, up[v][0].second});
            max2(up[u][0], up[u][1], {b[v]-1, v});
        }
    }
}

void dfs2(int u, int p)
{
    pii p1, p2;
    p1 = p2 = PINF;
    max2(p1, p2, up[u][0]);
    max2(p1, p2, up[u][1]);
    if (p != 0) {
        if (up[p][0].second != u)
            max2(p1, p2, {up[p][0].first-1, up[p][0].second});
        if (up[p][1].second != u)
            max2(p1, p2, {up[p][1].first-1, up[p][1].second});
        max2(p1, p2, {b[p]-1, p});
    }
    up[u][0] = p1;
    up[u][1] = p2;

    for (auto v : G[u]) {
        if (v != p)
            dfs2(v, u);
    }
}

bool visited[N];

int main()
{
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);

    int x = 1, sz = 0;
    visited[x] = true;
    vector<int> vislist(1, 1);
    while (k--) {
        x = up[x][0].second;
        if (sz == 0 && visited[x]) {
            sz = vislist.size() - (find(vislist.begin(), vislist.end(), x)-vislist.begin());
            k %= sz;
        }
        visited[x] = true;
        vislist.push_back(x);
    }
    printf("%d\n", x);

    return 0;
}
