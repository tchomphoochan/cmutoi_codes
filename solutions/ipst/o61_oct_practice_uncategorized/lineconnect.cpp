#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;;
using pll = pair<ll, ll>;

// ===================================================

const int INF = 1.1e9;
// const ll INF = 1e18;

const int N = 100010;

int x[N];
int parent[N];
int prefmax[N], postmin[N];

int root(int u)
{
    if (parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}

void join(int u, int v)
{
    u = root(u);
    v = root(v);
    parent[u] = v;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i]);
        parent[i] = i;
    }
    if (n == 1)  {
        printf("0\n");
        return 0;
    } else if (n == 2) {
        printf("%d\n", max(x[1], x[2]) - min(x[1], x[2]));
        return 0;
    }
    for (int i = 0; i < n-2; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        join(u, v);
    }

    vector<int> g1, g2;
    int g1r = 0, g2r = 0;
    for (int i = 1; i <= n; ++i) {
        int r = root(i);
        if (g1r == 0) {
            g1r = r;
            g1.push_back(x[i]);
        } else if (r == g1r) {
            g1.push_back(x[i]);
        } else if (g2r == 0) {
            g2r = r;
            g2.push_back(x[i]);
        } else {
            g2.push_back(x[i]);
        }
    }
    g1.push_back(-INF);
    g2.push_back(-INF);
    sort(g1.begin(), g1.end());
    sort(g2.begin(), g2.end());
    int m1 = g1.size()-1;
    int m2 = g2.size()-1;

    prefmax[0] = -INF;
    postmin[m2+1] = INF;
    for (int i = 1; i <= m2; ++i)
        prefmax[i] = max(prefmax[i-1], g2[i]);
    for (int i = m2; i >= 1; --i)
        postmin[i] = min(postmin[i+1], g2[i]);
    
    int ans = INF;
    for (int i = 1; i <= m1; ++i) {
        int ptr = lower_bound(g2.begin(), g2.end(), g1[i]) - g2.begin();
        int d1 = g1[i] - prefmax[ptr-1];
        int d2 = postmin[ptr] - g1[i];
        ans = min(ans, min(d1, d2));
    }
    
    printf("%d\n", ans);
    return 0;
}