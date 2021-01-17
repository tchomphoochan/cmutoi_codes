#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

vector<int> G[N];
int parent[N];
int cnt[N];
int max1[N], max2[N];

void dfs(int u, int p)
{
    cnt[u] = 1;
    parent[u] = p;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            cnt[u] += cnt[v];
            if (cnt[v] > cnt[max1[u]]) {
                max2[u] = max1[u];
                max1[u] = v;
            } else if (cnt[v] > cnt[max2[u]]) {
                max2[u] = v;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    ll ans = 0;
    for (int u = 2; u <= n; ++u) {
        int p = parent[u];
        int down = cnt[max1[u]];
        int up = n-cnt[p];
        int side = max1[p] == u ? cnt[max2[p]] : cnt[max1[p]];
        ll cand = (ll)down * max(up, side);
        ans = max(ans, cand);
    }
    printf("%lld", ans);

    return 0;
}