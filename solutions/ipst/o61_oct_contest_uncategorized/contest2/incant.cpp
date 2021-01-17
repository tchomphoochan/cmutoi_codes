#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 10010;
const int M = 1<<7;

int n, m;
int p[M], parent[N][M];
ll dp[N][M];

vector<int> find_cycle(int i, int j)
{
    vector<int> cycle;
    cycle.push_back(j);
    while (true) {
        j = parent[i++][j];
        cycle.push_back(j);
        if (cycle.front() == cycle.back())
            break;
        if (i > n-m) {
            cycle.push_back(1);
            break;
        }
    }
    cycle.pop_back();
    return cycle;
}

int main()
{
    scanf("%d%d", &n, &m);
    int mx = 0;
    for (int i = 0; i < (1<<m); ++i) {
        scanf("%d", &p[i]);
        mx = max(mx, p[i]);
    }
    
    ll ans;
    int ansv;
    for (int i = min(n-m, 10000); i >= 0; --i) {
        ans = 0;
        for (int j = 0; j < (1<<m); ++j) {
            int sl = (j<<1)&((1<<m)-1);
            int nv = dp[i+1][j]+p[sl];
            if (nv > dp[i][sl]) {
                dp[i][sl] = nv;
                parent[i][sl] = j;
            }
            nv = dp[i+1][j]+p[sl|1];
            if (nv > dp[i][sl|1]) {
                dp[i][sl|1] = nv;
                parent[i][sl|1] = j;
            }
        }
        for (int j = 0; j < (1<<m); ++j) {
            if (dp[i][j] > ans) {
                ans = dp[i][j];
                ansv = j;
            }
        }
    }

    if (n-m <= 10000) {
        printf("%lld", ans);
    } else {
        n = n-m+1;
        vector<int> c = find_cycle(0, ansv);
        ll sum = 0;
        for (auto x : c)
            sum += p[x];
        ll tt = sum*(n/c.size());
        n %= c.size();
        for (int i = 0; i < n; ++i)
            tt += p[i];
        printf("%lld", tt);
    }

    return 0;
}