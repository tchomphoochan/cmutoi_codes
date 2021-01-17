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

const int N = 1e5+10;

int main()
{
    //time_t begin = clock();

    int T;
    scanf("%d", &T);
    for1(t, T) {
        int n;
        scanf("%d", &n);

        ll W[N] = {};
        ll lis[N] = {};
        for1(i, n+5) lis[i] = 1e18;
        ll len = 0;
        for1(i, n) {
            scanf("%lld", &W[i]);
            ll jl = upper_bound(lis, lis+n+3, W[i]*6)-1 - lis;
            rofx(j, jl, 0) {
                len = max(len, (ll)j+1);
                if (lis[j]+W[i] <= lis[j+1])
                    lis[j+1] = min(lis[j+1], lis[j]+W[i]);
                else
                    break;
            }
        }

        printf("Case #%d: %lld\n", t, len);
    }

    //time_t end = clock();
    //fprintf(stderr, "%.3f seconds\n", ((double)end-begin)/CLOCKS_PER_SEC);

    return 0;
}