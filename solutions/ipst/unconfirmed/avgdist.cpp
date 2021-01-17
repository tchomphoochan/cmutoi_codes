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

const int N = 30010;
const int K = 12;

int n, num[N], par[N], rot[N], pos[N], spi[N], sz[N], in[N], out[N], rev[N], tick=0;
vector<pii> G[N];
ll dep[N], len[N], qsl[N];

void hld1(int u, int p=0, ll d=0, ll l=0)
{
    in[u] = ++tick;
    par[u] = p;
    dep[u] = d;
    len[u] = l;
    sz[u] = 1;
    pii best(0, 0);
    fora(v, G[u]) if (v.F != p) {
        hld1(v.F, u, d+v.S, v.S);
        sz[u] += sz[v.F];
        setmax(best, pii(sz[v.F], v.F));
    }
    spi[u] = best.S;
    out[u] = ++tick;
}

void hld2()
{
    int cnt = 0;
    for1(u, n) if (spi[par[u]] != u) {
        for (int v = u; v; v = spi[v]) {
            pos[v] = ++cnt;
            rev[cnt] = v;
            rot[v] = u;
        }
    }
}

struct SegT {
    ll ft[N] = {}, ft2[N] = {};
    void update(ll f[], int i, ll x) {
        for (; i < N; i += i&-i)
            f[i] += x;
    }
    void update(int i, ll x) {
        update(ft, i, x);
        update(ft2, i, qsl[i-1]*-x);
    }
    void update(int a, int b, ll x) {
        update(a, x);
        update(b+1, -x);
    }
    ll query(ll f[], int i) {
        ll ans = 0;
        for (; i > 0; i -= i&-i)
            ans += f[i];
        return ans;
    }
    ll query(int i) {
        return qsl[i]*query(ft, i) + query(ft2, i);
    }
    ll query(int a, int b) {
        return query(b) - query(a-1);
    }
};

bool isances(int u, int v)
{
    return in[u] <= in[v] && out[v] <= out[u];
}

ll querypath(int u, int v, SegT &ft)
{
    //W("query path", u, v);
    ll ans = 0;
    while (rot[u] != rot[v]) {
        if (isances(rot[v], u))
            swap(u, v);
        ans += ft.query(pos[rot[v]], pos[v]);
        v = par[rot[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    ans += ft.query(pos[u]+1, pos[v]);
    return ans;
}

void updatepath(int u, int v, ll x, SegT &ft)
{
    //W("update path", u, v, x);
    while (rot[u] != rot[v]) {
        if (isances(rot[v], u))
            swap(u, v);
        ft.update(pos[rot[v]], pos[v], x);
        v = par[rot[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    ft.update(pos[u]+1, pos[v], x);
}

int k, gcnt[K];
ull sumdep[K], ans[K];
SegT ft[K];

void addnode(int u, int g)
{
    ans[g] += sumdep[g] + (ull)gcnt[g]*dep[u] - 2*(ull)querypath(u, 1, ft[g]);
    sumdep[g] += (ull)dep[u];
    ++gcnt[g];
    updatepath(u, 1, 1, ft[g]);
}

void remnode(int u, int g)
{
    updatepath(u, 1, -1, ft[g]);
    sumdep[g] -= (ull)dep[u];
    --gcnt[g];
    ans[g] -= sumdep[g] + (ull)gcnt[g]*dep[u] - 2*(ull)querypath(u, 1, ft[g]);
}

int _main()
{
    R(n, k);
    for1(i, n) R(num[i]);
    forn(i, n-1) {
        int a, b, l;
        R(a, b, l);
        G[a].eb(b, l);
        G[b].eb(a, l);
    }
    hld1(1);
    hld2();
    for1(i, n) qsl[i] = qsl[i-1] + len[rev[i]];
    for1(i, n) addnode(i, num[i]);
    //for1(i, n) W("node", i, "is in pos", pos[i], "and has dep", dep[i]);
    //for1(i, k) W("group", i, "has", gcnt[i], "nodes", "sum = ", sumdep[i], "and answer =", ans[i]);

    int q;
    R(q);
    while (q--) {
        int t, x, y;
        R(t, x);
        if (t == 1) {
            ll gc = (gcnt[x]*(gcnt[x]-1))/2;
            long double ret = gc == 0 ? 0.0 : ans[x]*((long double)1)/gc;
            printf("%.20Lf\n", ret);
        } else {
            R(y);
            remnode(x, num[x]);
            num[x] = y;
            addnode(x, num[x]);
        }
    }
    
    return 0;
}