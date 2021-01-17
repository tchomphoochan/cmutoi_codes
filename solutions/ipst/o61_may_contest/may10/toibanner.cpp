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

int X[N];

int main()
{
    int n;
    scanf("%d", &n);
    for1(i, n) scanf("%d", &X[i]);
    vector<int> seq;
    int a, b;
    scanf("%d", &a);
    seq.pb(X[a]);
    forn(i, n/2) {
        scanf("%d%d", &a, &b);
        seq.pb(X[a]);
        seq.pb(X[b]);
        sort(all(seq));
        vector<int> vl(seq.size()), vr(seq.size());
        int last = -1, sum = 0;
        forn(i, seq.size()) {
            if (last == -1)
                last = seq[i];
            else {
                sum += seq[i]-last;
                vl[i] = sum, last = -1;
            }
        }
        last = -1, sum = 0;
        rofn(i, seq.size()) {
            if (last == -1)
                last = seq[i];
            else {
                sum += last-seq[i];
                vr[i] = sum, last = -1;
            }
        }
        int ans = 1e9;
        forn(i, seq.size()) {
            if (i%2 == 0)
                ans = min(ans, (i-1 >= 0 ? vl[i-1] : 0)+(i+1 < seq.size() ? vr[i+1] : 0));
        }
        printf("%d\n", ans);
    }

    return 0;
}