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

#include "recoverlib.h"

const int N = 3010;

bool comp[N];
vector<int> primes;
int ans[N], cnt[N];
mt19937 RNG(314159265);

int main()
{
    int n = recover_init();
    forx(i, 2, n) {
        if (comp[i]) continue;
        if (cnt[i] = recover_query(1, n, i))
            primes.pb(i);
        for (int j = i*2; j <= n; j += i)
            comp[j] = true;
    }
    if (primes.size() > 20) {
        sort(primes.begin()+20, primes.end(), [&] (int a, int b) {
            return cnt[a] > cnt[b];
        });
        if (primes.size() > 30)
            shuffle(primes.begin()+30, primes.end(), RNG);
    }
    for1(i, n) {
        vector<pii> ans;
        int tt = 1;
        fora(p, primes) {
            //if (tt*p > n) break;
            int c = 0, x = p;
            while (tt*p <= n && recover_query(i, i, x)) {
                ++c;
                tt *= p;
                x *= p;
            }
            if (c > 0)
                ans.eb(p, c);
        }
        if (ans.size() == 1)
            tt *= ans[0].F;
        ::ans[i] = tt;
    }
    recover_answer(ans);

    return 0;
}