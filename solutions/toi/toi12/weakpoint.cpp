/**
 * toi12_peak
 * 
 * aquablitz11 (2017)
 * The code is very ugly.
 */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define N 500010

vector<int> G[N];
bool visited[N];
bool cycle[N];

int findCycle(int u, int p)
{
    if (visited[u])
        return u;
    visited[u] = true;
    for (auto v : G[u]) {
        if (v == p)
            continue;
        int ret = findCycle(v, u);
        if (ret != 0) {
            cycle[u] = true;
            if (ret == u)
                return 0;
            else
                return ret;    
        }
    }
    return 0;
}

int countRemoved(int u, int p, bool nocycle)
{
    int sum = 0;
    visited[u] = true;
    for (auto v : G[u]) {
        if (v == p)
            continue;    
        if (nocycle && cycle[v])
            continue;
        if (visited[v])
            continue;
        sum += countRemoved(v, u, nocycle);
    }
    return sum+1;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    findCycle(1, 0);
    fill(visited+1, visited+n+1, false);

    int mx = 0;
    int ix = 0;
    if (cycle[m]) {
        for (int u = 1; u <= n; ++u) {
            if (!cycle[u] || u == m)
                continue;
            int val = countRemoved(u, 0, true)-1;
            if (val > mx) {
                mx = val;
                ix = u;
            }
        }
    }

    for (auto v : G[m]) {
        if (cycle[m] && cycle[v])
            continue;
        int val = countRemoved(v, m, false)-1;
        if (val > mx || (val == mx && ix < v)) {
            mx = val;
            ix = v;
        }
    }

    if (mx == 0)
        ix = m == 1 ? 2 : 1;    
    printf("%d\n%d\n", ix, mx);
    return 0;
}