#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, k, q;

int dist[N], ft[N], parent[N], root[N], root2[N];
vector<int> G[N];

int query(int i)
{
    int ans = 0;
    for (; i > 0; i -= i&-i)
        ans += ft[i];
    return ans;
}

void update(int i, int x)
{
    for (; i <= k; i += i&-i)
        ft[i] += x;
}

int inCircle(int a, int b)
{
    if (a > b) swap(a, b);
    int s1 = query(b-1) - query(a-1);
    int s2 = query(k) - s1;
    return min(s1, s2);
}

void dfs(int u, int r, int r2)
{
    root[u] = r;
    root2[u] = r2;
    if (u > k && parent[u] > k)
        dist[u] += dist[parent[u]];
    for (auto v : G[u])
        dfs(v, r, r == r2 ? v : r2);
}

int distance(int a, int b)
{
    int ad = a <= k ? 0 : dist[a];
    int bd = b <= k ? 0 : dist[b];

    if (root[a] == root[b]) {
        if (root2[a] == root2[b])
            return abs(ad - bd);
        else
            return ad + bd;
    }

    return ad + bd + inCircle(root[a], root[b]);
}

int main()
{
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &dist[i]);
        update(i, dist[i]);
    }

    for (int i = k+1; i <= n; ++i) {
        scanf("%d%d", &parent[i], &dist[i]);
        G[parent[i]].push_back(i);
    }

    for (int i = 1; i <= k; ++i)
        dfs(i, i, i);
    
    while (q--) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (t == 0) {
            update(x, y-dist[x]);
            dist[x] = y;
        } else {
            printf("%d\n", distance(x, y));
        }
    }

    return 0;
}