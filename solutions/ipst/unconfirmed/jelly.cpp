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

const int N = 1000010;
const ll MOD = 1e9+7;

ll mod(ll a) { a %= MOD; if (a < 0) a += MOD; return a; }

struct Fenwick {
    int n;
    vector<ll> ft1, ft2;
    Fenwick() {}
    Fenwick(int n) : n(n), ft1(n+1, 0), ft2(n+1, 0) {}
    ll query(vector<ll> &ft, int i) {
        ll ans = 0;
        for (; i > 0; i -= i&-i)
            ans = mod(ans+ft[i]);
        return ans;
    }
    void update(vector<ll> &ft, int i, ll x) {
        x = mod(x);
        for (; i <= n; i += i&-i)
            ft[i] = mod(ft[i] + x);
    }
    ll query(int i) {
        return mod(mod(query(ft1, i)*i) + query(ft2, i));
    }
    void update(int i, ll x) {
        x = mod(x);
        update(ft1, i, x);
        update(ft2, i, -x*(i-1));
    }
    ll query(int a, int b) {
        return mod(query(b) - query(a-1));
    }
    void update(int a, int b, ll x) {
        if (a > b) return;
        update(a, x);
        update(b+1, -x);
    }
};

int sx, sy, sz, t;
Fenwick ftx, fty, ftz;

void update(int x1, int x2, int y1, int y2, int z1, int z2, ll v)
{
    if (x1 > x2 || y1 > y2 || z1 > z2) return;
    ftx.update(x1, x2, mod(v*(y2-y1+1))*(z2-z1+1));
    fty.update(y1, y2, mod(v*(x2-x1+1))*(z2-z1+1));
    ftz.update(z1, z2, mod(v*(y2-y1+1))*(x2-x1+1));
}

int _main()
{
    R(sx, sy, sz, t);
    ftx = Fenwick(sx);
    fty = Fenwick(sy);
    ftz = Fenwick(sz);
    while (t--) {
        int q; R(q);
        if (q == 0) {
            int x1, x2, y1, y2, z1, z2, v1, v2;
            R(x1, x2, y1, y2, z1, z2, v1, v2);

            update(x1, x2, y1, y2, z1, z2, v1);
            int X1[] = {1, x2+1};
            int X2[] = {x1-1, sx};
            int Y1[] = {1, y2+1};
            int Y2[] = {y1-1, sy};
            int Z1[] = {1, z2+1};
            int Z2[] = {z1-1, sz};
            forn(xt, 2) forn(yt, 2) forn(zt, 2)
                update(X1[xt], X2[xt], Y1[yt], Y2[yt], Z1[zt], Z2[zt], v2);

        } else {
            int d, lo, hi;
            R(d, lo, hi);
            if (lo > hi) {
                W(0);
                continue;
            }
            setmax(lo, 1);
            if (d == 1) W(ftx.query(lo, min(hi, sx)));
            if (d == 2) W(fty.query(lo, min(hi, sy)));
            if (d == 3) W(ftz.query(lo, min(hi, sz)));
        }
    }
    
    return 0;
}