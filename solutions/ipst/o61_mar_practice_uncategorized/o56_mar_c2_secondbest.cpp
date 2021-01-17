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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
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

struct DSU {
    int n, mcnt;
    vector<int> parent;
    DSU() {}
    DSU(int n) : n(n), mcnt(0), parent(n+1) {
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }
    int root(int u) {
        if (parent[u] == u) return u;
        return parent[u] = root(parent[u]);
    }
    bool join(int u, int v) {
        u = root(u), v = root(v);
        if (u == v) return false;
        parent[v] = u;
        return ++mcnt;
    }
};

const int N = 100010;
const int M = 200010;
const ll INF = 1e18;

int n, m;
DSU dsu(N);
pair<int, pii> E[M];
vector<pii> G[N];

int dep[N], par[N], spi[N], rot[N], pos[N], t[N<<1], in[N], out[N], tick;

int dfs(int u, int p)
{
    in[u] = ++tick;
    par[u] = p;
    dep[u] = dep[p]+1;
    int sum = 1;
    pii mx = {0, 0};
    fora(v, G[u]) if (v.F != p) {
        int now = dfs(v.F, u);
        sum += now;
        setmax(mx, {now, v.F});
    }
    spi[u] = mx.S;
    out[u] = ++tick;
    return sum;
}

void dfs1(int u, int p)
{
    fora(v, G[u]) if (v.F != p) {
        t[pos[v.F]+n] = v.S;
        dfs1(v.F, u);
    }
}

void hld()
{
    dfs(1, 0);
    int idx = 0;
    for1(i, n) if (spi[par[i]] != i)
        for (int u = i; u; u = spi[u])
            rot[u] = i, pos[u] = idx++;
    dfs1(1, 0);
    rof1(i, n-1) t[i] = max(t[i<<1], t[i<<1|1]);
}

int tquery(int l, int r)
{
    int ans = 0;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if (l&1) setmax(ans, t[l++]);
        if (r&1) setmax(ans, t[--r]);
    }
    return ans;
}

bool isanc(int u, int v) { return (in[u] <= in[v] && out[v] <= out[u]); }
int query(int u, int v)
{
    int ans = 0;
    while (rot[u] != rot[v]) {
        if (isanc(rot[v], u)) swap(u, v);
        setmax(ans, tquery(pos[rot[v]], pos[v]));
        v = par[rot[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    setmax(ans, tquery(pos[u]+1, pos[v]));
    return ans;
}

int _main()
{
    R(n, m);
    forn(i, m) {
        int u, v, w;
        R(u, v, w);
        E[i] = {w, {u, v}};
    }
    sort(E, E+m);
    ll sum = 0, ans = INF;
    forn(i, m) {
        int u, v, w = E[i].F;
        tie(u, v) = E[i].S;
        if (dsu.join(u, v)) {
            G[u].eb(v, w);
            G[v].eb(u, w);
            sum += w;
        }
    }
    hld();
    forn(i, m) {
        int u, v, w = E[i].F;
        tie(u, v) = E[i].S;
        ll now = sum + w - query(u, v);
        if (now > sum) setmin(ans, now);
    }
    W(ans);

    return 0;
}