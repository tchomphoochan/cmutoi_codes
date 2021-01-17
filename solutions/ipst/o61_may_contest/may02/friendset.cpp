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
#define fora(x, v) for (auto x : v)
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)

const int N = 100010;
const ll PB = 98765431;

ll PP[N], val[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    PP[0] = 1;
    for1(i, n) {
        PP[i] = PP[i-1]*PB;
    }
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        val[u] += PP[v];
        val[v] += PP[u];
    }
    ll ans = 0;
    map<ll, ll> cnt;
    for1(i, n) {
        ans += cnt[val[i]];
        ++cnt[val[i]];
    }
    cnt.clear();
    for1(i, n) {
        val[i] += PP[i];
        ans += cnt[val[i]];
        ++cnt[val[i]];
    }
    printf("%lld\n", ans);

    return 0;
}