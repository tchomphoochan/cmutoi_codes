#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;;
using pll = pair<ll, ll>;

// ===================================================

const int INF = 1e9;
// const ll INF = 1e18;


const int N = 100010;

int n;
int parent[N];
vector<int> G[N];

bool visited[N];
bool iscycle[N];

int dp[N][2], cdp[N][2];

vector<int> find_cycle(int s)
{
    int u;
    for (u = s; !visited[u]; u = parent[u])
        visited[u] = true;
    int end = u;
    vector<int> cycle;
    cycle.push_back(u);
    iscycle[u] = true;
    for (u = parent[u]; u != end; u = parent[u]) {
        cycle.push_back(u);
        iscycle[u] = true;
    }
    return cycle;
}

int solve_mis(int u, int c)
{
    visited[u] = true;
    int &ans = dp[u][c];
    if (ans != -1) return ans;

    ans = c;
    for (auto v : G[u]) {
        if (iscycle[v]) continue;
        if (c == 0) ans += max(solve_mis(v, 0), solve_mis(v, 1));
        else ans += solve_mis(v, 0);
    }

    return ans;
}

int solve(int s)
{
    vector<int> cycle = find_cycle(s);
    vector<int> mb, mw;
    for (auto u : cycle) {
        mw.push_back(solve_mis(u, 0));
        mb.push_back(solve_mis(u, 1));
    }

    int m = cycle.size();
    cdp[m][0] = cdp[m][1] = 0;
    for (int i = m-1; i >= 0; --i) {
        cdp[i][0] = mw[i] + max(cdp[i+1][0], cdp[i+1][1]);
        cdp[i][1] = mb[i] + cdp[i+1][0];
    }
    int ans1 = cdp[0][0];
    cdp[m-1][0] = cdp[m-1][1] = 0;
    for (int i = m-2; i >= 0; --i) {
        cdp[i][0] = mw[i] + max(cdp[i+1][0], cdp[i+1][1]);
        cdp[i][1] = mb[i] + cdp[i+1][0];
    }
    int ans2 = cdp[0][1] + mw[m-1];

    return max(ans1, ans2);
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    
    int TCALL;
    scanf("%d", &TCALL);
    while (TCALL--) {
        
        scanf("%d", &n);
        for (int i = 0; i <= n; ++i) {
            parent[i] = visited[i] = iscycle[i] = 0;
            dp[i][0] = dp[i][1] = cdp[i][0] = cdp[i][1] = -1;
            G[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &parent[i]);
            G[parent[i]].push_back(i);
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i])
                ans += solve(i);
        }

        printf("%d\n", n-ans);
    }
    
    return 0;
}