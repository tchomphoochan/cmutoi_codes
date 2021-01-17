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

int n, q;
int deg[N];
int U[N], V[N];
ll WE[N];
bool eic[N];
vector<int> G[N];

int lazyt[N<<1];
ll lazyv[N<<1];
int cntcyc[N<<1];
pii mxcyc[N<<1];
ll sumw[N<<1];

pii setcyc(pii a, pii b)
{
    if (a.F == b.F) return pii(a.F, a.S+b.S);
    else return max(a, b);
}

void comb(int p, int b, int e)
{
    cntcyc[p] = cntcyc[p<<1] + cntcyc[p<<1|1];
    mxcyc[p] = setcyc(mxcyc[p<<1], mxcyc[p<<1|1]);
    sumw[p] = sumw[p<<1] + sumw[p<<1|1];
}

void addto(int p, int lt, ll lv)
{
    if (lt == 2) {
        lazyt[p] = 2;
        lazyv[p] = lv;
        return;
    }
    if (lazyt[p] != 2)
        lazyt[p] = 1;
    lazyv[p] += lv;
}

void push(int p, int b, int e)
{
    if (!lazyt[p]) return;
    if (lazyt[p] == 1) { // add
        if (mxcyc[p].S)
            mxcyc[p] = pii(mxcyc[p].F + lazyv[p], mxcyc[p].S);
        sumw[p] += (e-b+1)*lazyv[p];
    } else if (lazyt[p] == 2) { // set
        if (cntcyc[p])
            mxcyc[p] = pii(lazyv[p], cntcyc[p]);
        sumw[p] = (e-b+1)*lazyv[p];
    }
    if (b != e) {
        addto(p<<1, lazyt[p], lazyv[p]);
        addto(p<<1|1, lazyt[p], lazyv[p]);
    }
    lazyt[p] = 0;
    lazyv[p] = 0;
}

void update(int l, int r, int t, int v, int p=1, int b=1, int e=n)
{
    push(p, b, e);
    if (l > r || b > r || e < l)
        return;
    if (b >= l && e <= r) {
        addto(p, t, v);
        push(p, b, e);
        return;
    }
    int m = (b+e)/2;
    update(l, r, t, v, p<<1, b, m);
    update(l, r, t, v, p<<1|1, m+1, e);
    comb(p, b, e);
}

void build(int p=1, int b=1, int e=n)
{
    if (b == e) {
        if (eic[b]) {
            cntcyc[p] = 1;
            mxcyc[p] = pii(WE[b], 1);
        }
        sumw[p] += WE[b];
        return;
    }
    int m = (b+e)/2;
    build(p<<1, b, m);
    build(p<<1|1, m+1, e);
    comb(p, b, e);
}

void print_tree(int p=1, int b=1, int e=n)
{
    printf("range [%d,%d]\n", b, e);
    printf("cntcyc = %d, mxcyc = %d, %d\n", cntcyc[p], mxcyc[p].F, mxcyc[p].S);
    printf("sumw = %lld, lazyt = %d, lazyv = %lld\n", sumw[p], lazyt[p], lazyv[p]);
    W("");

    if (b != e) {
        int m = (b+e)/2;
        print_tree(p<<1, b, m);
        print_tree(p<<1|1, m+1, e);
    }
}

int _main()
{
    R(n, q);
    for1(i, n) {
        int u, v, w;
        R(u, v, w);
        U[i] = u, V[i] = v, WE[i] = w;
        ++deg[u], ++deg[v];
        G[u].pb(v);
        G[v].pb(u);
    }
    queue<int> Q;
    for1(i, n) if (deg[i] == 1) Q.push(i);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        --deg[u];
        fora(v, G[u]) if (deg[v]) if (--deg[v] == 1) Q.push(v);
    }
    for1(i, n) if (deg[U[i]] && deg[V[i]]) eic[i] = true;
    build();
    //print_tree();

    while (q--) {
        int qt, s, t, c;
        R(qt, s, t, c);
        update(s, t, qt, c);
        W(sumw[1]-mxcyc[1].F, mxcyc[1].S);
        //print_tree();
    }
    
    return 0;
}