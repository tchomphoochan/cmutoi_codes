#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define F first
#define S second
#define forx(i, x, y) for (int i = (x); i <= (y); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rofx(i, x, y) for (int i = x; i >= y; --i)
#define rofn(i, n) for (int i = n-1; i >= 0; --i)
#define rof1(i, n) for (int i = n; i >= 1; --i)
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define fora(x, v) for (auto x : v)

const int N = 100010;

int n, k;
vector<int> G[N];

int solve(int u)
{
    vector<int> val;
    int sum = 0;
    fora(v, G[u]) {
        int x = solve(v);
        if (x == -1) return -1;
        if (x > 0) sum += x;
    }
    if (sum < k-1) return sum+1;
    if (sum == k-1) return 0;
    if (sum > k-1) return -1;
}

int main()
{
    scanf("%d%d", &n, &k);
    assert(n <= 2000);
    forx(u, 2, n) {
        int p;
        scanf("%d", &p);
        G[p].pb(u);
        if (solve(1) == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}