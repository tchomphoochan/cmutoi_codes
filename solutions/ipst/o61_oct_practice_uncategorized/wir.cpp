#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;
const int N = 100010;

int h[N], diff[N];
set<pii> diffset;
int parent[N];

pii query[N];
int qans[N];
int cnt = 0;

int root(int u)
{
    if (parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    h[0] = INF; h[n+1] = -INF;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
        diff[i-1] = h[i]-h[i-1];
        diffset.insert({diff[i-1], i-1});
        parent[i] = i;
    }
    parent[n+1] = n+1;
    diff[n] = h[n+1]-h[n];
    diffset.insert({diff[n], n});

    for (int i = 0; i < m; ++i) {
        scanf("%d", &query[i].first);
        query[i].second = i;
    }
    sort(query, query+m, greater<pii>());

    for (int i = 0; i < m; ++i) {
        int k = query[i].first;

        auto ptr = diffset.lower_bound({k+1, -INF});
        for (auto it = ptr; it != diffset.end(); ) {
            int i = it->second;
            if (parent[i] != i) {
                it = diffset.erase(it);
                continue;
            }
            int j;
            for (j = root(i+1); j <= n && h[j]-h[i] > k; ) {
                ++cnt;
                parent[j] = parent[j+1];
                ++j;
                j = root(j);
            }
            ++it;
            diffset.erase({diff[i], i});
            diff[i] = h[root(i+1)]-h[i];
            diffset.insert({diff[i], i});
        }

        qans[query[i].second] = cnt;
    }

    for (int i = 0; i < m; ++i)
        printf("%d\n", qans[i]);

    return 0;
}