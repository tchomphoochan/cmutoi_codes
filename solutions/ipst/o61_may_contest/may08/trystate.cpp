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
int par[N], sum[N], val[N];
int cnt1 = 0;

void setval(int u, int x)
{
    if (val[u] == -1) --cnt1;
    sum[par[u]] += x-val[u];
    val[u] = x;
    if (val[u] == -1) ++cnt1;
}

void update(int u)
{
    if (u == 0) return;
    if (sum[u] < k-1) setval(u, sum[u]+1);
    else if (sum[u] == k-1) setval(u, 0);
    else { setval(u, -1); return; }
    update(par[u]);
}

int main()
{
    scanf("%d%d", &n, &k);
    setval(1, 1);
    forx(u, 2, n) {
        int p;
        scanf("%d", &p);
        par[u] = p;
        update(u);
        if (cnt1 == 0 && val[1] == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}