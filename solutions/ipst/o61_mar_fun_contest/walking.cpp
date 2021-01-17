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

const int N = 6010;
const int INF = 1e9;

int n, k;
vector<int> G[N];
int val[N];

int ans = INF;
bool rem[N];

vector<int> coord;
int pos(int x) { return lower_bound(all(coord), x) - coord.begin(); }
int c, seg[N<<2], tim[N<<2], tick = 0;
int &get(int i) { if (tim[i] != tick) tim[i] = tick, seg[i] = INF; return seg[i]; }

int query(int l, int r) {
    int ret = INF;
    for (l += c, r += c+1; l < r; l >>= 1, r >>= 1) {
        if (l&1) setmin(ret, get(l++));
        if (r&1) setmin(ret, get(--r));
    }
    return ret;
}

void update(int i, int x) {
    for (setmin(get(i += c), x); i >>= 1; )
        get(i) = min(get(i<<1), get(i<<1|1));
}

void dfs(int u, int p, int s, int l, int q) {
    if (q == 0) {
        coord.pb(s);
        coord.pb(k-s);
    } else if (q == 1) {
        if (s >= k) setmin(ans, l);
        else setmin(ans, query(pos(k-s), c-1) + l);
    } else {
        update(pos(s), l);
    }
    fora(v, G[u]) if (!rem[v] && v != p)
        dfs(v, u, s+val[v], l+1, q);
}

int sz[N];
int mns, mnu;

void dfs0(int u, int p)
{
    sz[u] = 1;
    fora(v, G[u]) if (!rem[v] && v != p) {
        dfs0(v, u);
        sz[u] += sz[v];
    }
}

void cen(int u, int p, int s)
{
    int cs = sz[s]-sz[u];
    fora(v, G[u]) if (!rem[v] && v != p) {
        setmax(cs, sz[v]);
        cen(v, u, s);
    }
    if (setmin(mns, cs)) mnu = u;
}

void rec(int u) {
    ++tick;
    dfs0(u, -1);
    mns = INF;
    cen(u, -1, u);
    //u = mnu;
    int x = val[u];
    k -= x;

    coord.clear();
    fora(v, G[u]) if (!rem[v])
        dfs(v, u, val[v], 1, 0);
    c = compress(coord);
    fora(v, G[u]) if (!rem[v]) {
        dfs(v, u, val[v], 1, 1);
        dfs(v, u, val[v], 1, 2);
    }

    k += x;
    rem[u] = true;
    fora(v, G[u]) if (!rem[v])
        rec(v);
}

int _main()
{
    R(n, k);
    forn(i, n) R(val[i]);
    forn(i, n-1) {
        int u, v;
        R(u, v);
        G[u].pb(v);
        G[v].pb(u);
    }

    rec(0);
    if (ans >= INF)
        ans = -1;
    W(ans);
    
    return 0;
}