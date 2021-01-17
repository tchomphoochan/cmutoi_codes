#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 100010;

int n, m;
vector<pii> G[N]; // time, to
int color[N];

bool dfs(int u, int c, int t)
{
    color[u] = c;
    for (auto iv : G[u]) {
        if (iv.first > t) break;
        int v = iv.second;
        if (color[v] == -1) {
            if (!dfs(v, c^1, t))
                return false;
        } else if (color[v] == c) {
            return false;
        }
    }
    return true;
}

bool check(int t)
{
    fill(color+1, color+n+1, -1);
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            if (!dfs(i, 0, t))
                return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back({i, v});
        G[v].push_back({i, u});
    }

    int l = 1;
    int r = m;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    printf("%d", r);

    return 0;
}