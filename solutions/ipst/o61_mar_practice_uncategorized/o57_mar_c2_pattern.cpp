// headers
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// types
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using dbl = double;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// loops
#define forx(i, x, y) for (int i = (x); i <= (y); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rofx(i, x, y) for (int i = x; i >= y; --i)
#define rofn(i, n) for (int i = n-1; i >= 0; --i)
#define rof1(i, n) for (int i = n; i >= 1; --i)
// define shortcuts
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
// functions
template<class T> inline bool hasbit(T x, int i) { return x&(1<<i); }
template<class T> inline T togbit(T x, int i) { return x|(1<<i); }
template<class T> inline T setbit(T x, int i) { return x|(1<<i); }
template<class T> inline T rembit(T x, int i) { return x&~(1<<i); }
template<class T> inline bool setmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool setmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> void compress(vector<T> &v) { sort(all(v)); v.resize(unique(all(v))-v.begin()); return v.size(); }
// read functions
int read_int() { int x; scanf("%d", &x); return x; }
int read_ll() { ll x; scanf("%" PRId64, &x); return x; }
int read_dbl() { dbl x; scanf("%lf", &x); return x; }
void _R(int &x) { x = read_int(); }
void _R(ll &x) { x = read_ll(); }
void _R(dbl &x) { x = read_dbl(); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
// print functions
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
int program();
int main() {
    //ios::sync_with_stdio(false), cin.tie(0);
    //time_t begin = clock();
    int ret = program();
    //time_t end = clock();
    //fprintf(stderr, "Program took %.3f seconds to compute\n", ((double)end-begin)/CLOCKS_PER_SEC);
    return ret;
}

/************************************************************
                CODE STARTS BELOW THIS POINT
************************************************************/

const int N = 1010;

char s[N], t[N];
int c[N], lps[N];

void match(int n, char s[], int m, char t[], int r)
{
    int j = 0;
    for (int i = 1; i < m; ) {
        if (t[i] == t[j])
            lps[i++] = ++j;
        else if (j != 0)
            j = lps[j-1];
        else
            lps[i++] = 0;
    }
    j = 0;
    for (int i = 0; i < n; ) {
        if (s[i] == t[j]) {
            ++i, ++j;
            if (j == m) {
                ++c[i-j-r];
                j = lps[j-1];
            }
        } else if (j != 0) {
            j = lps[j-1];
        } else {
            ++i;
        }
    }
}

int program()
{
    int n, q, m;
    scanf("%d%d %s", &n, &q, s);
    while (q--) {
        scanf("%d %s", &m, t);
        int p = 0, cnt = 1, ans = 0;
        for (int i = 0; i < m; ++i) {
            if (t[i] == '?') {
                if (p < i) {
                    ++cnt;
                    match(n, s, i-p, t+p, p);
                }
                p = i+1;
            }
        }
        match(n, s, m-p, t+p, p);
        for (int i = 0; i < n; ++i) {
            if (c[i] == cnt)
                ++ans;
            c[i] = 0;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}