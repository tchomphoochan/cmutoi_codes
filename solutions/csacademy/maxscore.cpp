#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e18;
const int N = 1e5+10;

vector<int> G[N];
ll dp[N], score[N], ans = -INF;

void compute(int u, int p)
{
    vector<ll> val;
    for (auto v : G[u]) {
        if (v != p) {
            compute(v, u);
            val.push_back(dp[v]);
        }
    }
    sort(val.begin(), val.end(), greater<ll>());

    dp[u] = score[1];
    ans = max(ans, score[0]);

    ll sum = 0;
    for (int i = 0; i < val.size(); ++i) {
        sum += val[i];
        dp[u] = max(dp[u], sum+score[i+2]);
        ans = max(ans, sum+score[i+1]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &score[i]);

    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    compute(1, 0);
    printf("%lld\n", ans);

    return 0;
}
