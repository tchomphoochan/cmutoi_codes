// headers
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
using pli = pair<ll, int>;
using piipi = pair<pii, int>;
using pipii = pair<int, pii>;
using plpii = pair<ll, pii>;
using ppii = pair<pii, pii>;
// loops
#define forx(i, x, y) for (int i = (x); i <= (y); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rofx(i, x, y) for (int i = x; i >= y; --i)
#define rofn(i, n) for (int i = n-1; i >= 0; --i)
#define rof1(i, n) for (int i = n; i >= 1; --i)
#define fora(x, v) for (auto x : v)
// define shortcuts
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
// functions
template<class T> inline bool hasbit(T x, int i) { return x&(1<<i); }
template<class T> inline T togbit(T x, int i) { return x|(1<<i); }
template<class T> inline T setbit(T x, int i) { return x|(1<<i); }
template<class T> inline T rembit(T x, int i) { return x&~(1<<i); }
template<class T> inline bool setmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool setmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> int compress(vector<T> &v) { sort(all(v)); v.resize(unique(all(v))-v.begin()); return v.size(); }
// read functions
int read_int() { int x; scanf("%d", &x); return x; }
ll read_ll() { ll x; scanf("%" SCNd64, &x); return x; }
ull read_ull() { ull x; scanf("%" SCNu64, &x); return x; }
dbl read_dbl() { dbl x; scanf("%lf", &x); return x; }
void _R(int &x) { x = read_int(); }
void _R(ll &x) { x = read_ll(); }
void _R(dbl &x) { x = read_dbl(); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
// print functions
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%" PRId64, x); }
void _W(const ull &x) { printf("%" PRIu64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
// pseudo-random number generator
template<class T, T x1, T x2, T x3, int y1, int y2, int y3>
struct PRNG {
    using S = typename make_signed<T>::type;
    T s;
    PRNG(T _s = 0) : s(_s) {}
    T next() {
        T z = (s += x1);
        z = (z ^ (z >> y1)) * x2;
        z = (z ^ (z >> y2)) * x3;
        return z ^ (z >> y3);
    }
    T next(T n) { return next() % n; }
    S next(S l, S r) { return l + next(r - l + 1); }
    T operator()() { return next(); }
    T operator()(T n) { return next(n); }
    S operator()(S l, S r) { return next(l, r); }
    static T gen(T s) { return PRNG(s)(); }
    template<class U>
    void shuffle(U first, U last) {
        size_t n = last - first;
        for (size_t i = 0; i < n; i++) swap(first[i], first[next(i + 1)]);
    }
};
PRNG<uint32_t, 0x9E3779B1, 0x85EBCA6B, 0xC2B2AE35, 16, 13, 16> r32;
PRNG<uint64_t, 0x9E3779B97F4A7C15, 0xBF58476D1CE4E5B9, 0x94D049BB133111EB, 30, 27, 31> r64;
// program
int _main();
int main() {
    //ios::sync_with_stdio(false), cin.tie(0);
    //time_t begin = clock();
    int ret = _main();
    //time_t end = clock();
    //fprintf(stderr, "Program took %.3f seconds to compute\n", ((double)end-begin)/CLOCKS_PER_SEC);
    return ret;
}

/************************************************************
                CODE STARTS BELOW THIS POINT
************************************************************/

const int N = 100010;
const int INF = 2e9;

struct data {
    int ix, dp, mx;
};

int n, l, u;
int A[N], dp[N], t[N<<1];

int getmax(int l, int r)
{
    --l, --r;
    int ans = -1;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if (l&1) setmax(ans, t[l++]);
        if (r&1) setmax(ans, t[--r]);
    }
    return ans;
}

void build()
{
    for (int i = 0; i < n; ++i)
        t[n+i] = A[i+1];
    for (int i = n-1; i > 0; --i)
        t[i] = max(t[i<<1], t[i<<1|1]);
}

int _main()
{
    R(n, l, u);
    for1(i, n) R(A[i]);
    build();

    auto dpcmp = [&] (data a, data b) {
        if (a.dp != b.dp) return a.dp < b.dp;
        if (a.mx != b.mx) return a.mx < b.mx;
        return a.ix < b.ix;
    };
    auto mxcmp = [&] (data a, data b) {
        if (a.ix != b.ix) return a.ix < b.ix;
        if (a.mx != b.mx) return a.mx < b.mx;
        return a.dp < b.dp;
    };

    multiset<data, decltype(dpcmp)> below(dpcmp);
    multiset<data, decltype(dpcmp)> abovedp(dpcmp);
    multiset<data, decltype(mxcmp)> abovemx(mxcmp);

    dp[0] = INF;
    for1(i, n) {
        //W("at i=", i);
        int x = i-l+1;
        if (x >= 1) { // insert to above
            //W("inserted", x, dp[x-1], getmax(x, i), "to above");
            if (dp[x-1] > getmax(x, i)) {
                abovedp.insert({x, dp[x-1], getmax(x, i)});
                abovemx.insert({x, dp[x-1], getmax(x, i)});
            } else {
                below.insert({x, dp[x-1], getmax(x, i)});
            }
        }
        // move things from above to below
        while (!abovedp.empty()) {
            data t = *abovedp.begin();
            //W("checking", t.ix, t.dp, t.mx);
            if (t.dp <= getmax(t.ix, i)) {
                //W("have to move cuz", t.dp, "<", getmax(t.ix, i));
                abovedp.erase(t);
                abovemx.erase(t);
                below.insert(t);
                //W("inserted", t.ix, t.dp, getmax(t.ix, i), "to below");
            } else {
                break;
            }
        }
        int ans = -1;
        // answer from below
        while (!below.empty()) {
            data t = *prev(below.end());
            if (t.ix < i-u+1) {
                below.erase(t);
                //W("erased", t.ix, t.dp, t.mx, "from below");
            } else {
                //W("set ans to", t.ix, t.dp);
                setmax(ans, min(t.dp, getmax(t.ix, i)));
                break;
            }
        }
        // answer from above
        while (!abovemx.empty()) {
            data t = *abovemx.begin();
            if (t.ix < i-u+1) {
                abovemx.erase(t);
                abovedp.erase(t);
                //W("erased", t.ix, t.dp, t.mx, "from above");
            } else {
                //setmax(ans, getmax(t.ix, i));
                setmax(ans, min(t.dp, getmax(t.ix, i)));
                break;
            }
        }

        dp[i] = ans;
        //W("dp", i, "=", dp[i]);
        //W("");
    }
    W(dp[n]);
    
    return 0;
}