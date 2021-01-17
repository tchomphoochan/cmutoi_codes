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

const int N = 500010;

int n, A[N], ft[N], ans[N];

void update(int i) {
    for (; i <= n; i += i&-i)
        ++ft[i];
}

int query(int x)
{
    int i = 0, ans = 0;
    rofn(j, 19) {
        int ni = i+(1<<j);
        if (ni <= n && ni-(ans+ft[ni]) < x) {
            ans += ft[ni];
            i = ni;
        }
    }
    return i+1;
}

int main()
{
    scanf("%d", &n);
    for1(i, n) scanf("%d", &A[i]);
    rof1(i, n) {
        ans[i] = query(i-A[i]);
        update(ans[i]);
    }
    for1(i, n) printf("%d ", ans[i]);

    return 0;
}