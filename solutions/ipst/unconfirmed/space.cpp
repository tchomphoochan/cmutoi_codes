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

const int N = 1<<18;
const ll INF = 1e8;

int n;
ll len[N], h[N], start[N], mn[N], mx[N];
ll sumlen[N<<1], sumdown[N<<1];
ll ltype[N<<1], lval[N<<1];

void push(int p, int b, int e) {
    if (ltype[p] == 0) return;

    sumdown[p] = (e-b+1)*lval[p]; // set down
    if (ltype[p] == 2) sumdown[p] -= sumlen[p];
    if (b != e) {
        ltype[p<<1] = ltype[p<<1|1] = ltype[p];
        lval[p<<1] = lval[p<<1|1] = lval[p];
    }
    ltype[p] = lval[p] = 0;
}

void merge(int p, int b, int e) {
    if (b != e) {
        sumlen[p] = sumlen[p<<1] + sumlen[p<<1|1];
        sumdown[p] = sumdown[p<<1] + sumdown[p<<1|1];
    }
}

void update(int l, int r, int t, ll x, int p=1, int b=1, int e=n) {
    push(p, b, e);
    if (l > r || b > r || e < l)
        return;
    if (b >= l && e <= r) {
        ltype[p] = t;
        lval[p] = x;
        push(p, b, e);
        return;
    }
    int m = (b+e)/2;
    update(l, r, t, x, p<<1, b, m);
    update(l, r, t, x, p<<1|1, m+1, e);
    merge(p, b, e);
}

pll query(int l, int r, int p=1, int b=1, int e=n) {
    push(p, b, e);
    if (l > r || b > r || e < l)
        return pll(0, 0);
    if (b >= l && e <= r)
        return pll(sumdown[p], sumlen[p]);
    int m = (b+e)/2;
    pll q1 = query(l, r, p<<1, b, m);
    pll q2 = query(l, r, p<<1|1, m+1, e);
    return pll(q1.F+q2.F, q1.S+q2.S);
}

void build(int p=1, int b=1, int e=n) {
    if (b==e) {
        sumlen[p] = len[b];
        sumdown[p] = start[b];
        return;
    }
    int m = (b+e)/2;
    build(p<<1, b, m);
    build(p<<1|1, m+1, e);
    merge(p, b, e);
}

int _main()
{
    int m;
    R(n, m);
    for1(i, n) R(len[i]);
    sort(len+1, len+n+1, greater<ll>());
    mx[0] = -INF, mn[0] = INF;
    for1(i, m) {
        R(h[i]);
        mn[i] = min(mn[i-1], h[i]);
        mx[i] = max(mx[i-1], h[i]+1);
    }
    len[n+1] = INF+5;
    mn[m+1] = 0;
    mx[m+1] = INF;

    for1(i, n) {
        int lo = 1;
        int hi = m;
        while (lo < hi) {
            int mid = (lo+hi+1)/2;
            if (mx[mid]-mn[mid] > len[i])
                hi = mid-1;
            else
                lo = mid;
        }
        if (h[lo+1] >= mx[lo]) start[i] = mn[lo];
        else if (h[lo+1] < mn[lo]) start[i] = mx[lo]-len[i];
        else assert(false);
    }
    build();

    ll ans = 0;
    for1(i, m) {
        // find first pole that fails
        int lo = 1;
        int hi = n+1;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            pll ret = query(mid, mid);
            ll down = ret.F;
            ll up = ret.F+ret.S;
            if (h[i] < down || h[i] >= up)
                hi = mid;
            else
                lo = mid+1;
        }
        if (lo == n+1)
            continue;

        pll pole = query(lo, lo);
        ll down = pole.F;
        ll up = pole.F+pole.S;

        pll ret = query(lo, n);
        int cnt = n-lo+1;
        if (h[i] >= up) {
            ll x = (h[i]+1)*cnt-(ret.F+ret.S);
            ans += x;
            update(lo, n, 2, h[i]+1);
        } else {
            ll x = ret.F - h[i]*cnt;
            ans += x;
            update(lo, n, 1, h[i]);
        }
    }
    W(ans);

    return 0;
}