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

mt19937 RNG(31415926);
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {

        int cnt[210] = {};
        bool used[210] = {};

        int n;
        scanf("%d", &n);
        forn(i, n) {

            int d;
            scanf("%d", &d);
            vector<int> f;
            forn(j, d) {
                int x;
                scanf("%d", &x);
                ++cnt[x];
                f.pb(x);
            }
            int mnv = 1e9;
            vector<int> poss;
            fora(x, f) {
                if (used[x]) continue;
                if (cnt[x] < mnv) {
                    mnv = cnt[x];
                    poss.clear();
                }
                if (cnt[x] <= mnv) {
                    poss.pb(x);
                }
            }

            if (poss.size() == 0) {
                printf("-1\n");
            } else {
                uniform_int_distribution<int> GEN(0, poss.size()-1);
                int x = poss[GEN(RNG)];
                printf("%d\n", x);
                used[x] = true;
            }
            fflush(stdout);

        }

    }

    return 0;
}