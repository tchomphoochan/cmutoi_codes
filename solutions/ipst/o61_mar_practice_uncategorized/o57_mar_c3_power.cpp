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
using R32 = PRNG<uint32_t, 0x9E3779B1, 0x85EBCA6B, 0xC2B2AE35, 16, 13, 16>;
R32 r32;
using R64 = PRNG<uint64_t, 0x9E3779B97F4A7C15, 0xBF58476D1CE4E5B9, 0x94D049BB133111EB, 30, 27, 31>;
R64 r64;
// program
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

const int N = 200010;

int n;
vector<int> G[N];
int val[N];

int stop = -1;
deque<int> cyc;
bool chk[N];
bool find_cycle(int u, int p)
{
    if (chk[u]) {
        stop = u;
        forn(i, n)
            chk[i] = false;
        return true;
    }
    chk[u] = true;
    fora(v, G[u]) {
        if (v != p && find_cycle(v, u)) {
            if (stop != -1) {
                cyc.pb(u);
                chk[u] = true;
            }
            if (stop == u)
                stop = -1;
            return true;
        }
    }
    return false;
}

struct T3 {
    int a, b, c;
    T3() {}
    T3(int a, int b, int c) : a(a), b(b), c(c) {}
    void setmax(int x) {
        if (x > a)
            c = b, b = a, a = x;
        else if (x > b)
            c = b, b = x;
        else if (x > c)
            c = x;
    }
};
int ans = 0, sum1 = 0, dpt[N], dp[N];
T3 t3val[N];
int tree_dp(int u, int p)
{
    T3 mx(0, 0, 0);
    fora(v, G[u]) {
        if (v != p && !chk[v])
            mx.setmax(tree_dp(v, u));
    }
    // case 3: pick every single one on cycle
    if (chk[u]) {
        sum1 += mx.a + val[u];
        setmax(ans, sum1);
    }
    t3val[u] = mx;
    return dpt[u] = mx.a + mx.b + val[u];
}

int program()
{
    // input
    R(n);
    forn(i, n) R(val[i]);
    forn(i, n) {
        int u, v;
        R(u, v);
        G[u].pb(v);
        G[v].pb(u);
    }

    // find cycle and do dp on each tree
    find_cycle(0, -1);
    fora(u, cyc)
        tree_dp(u, u);

    // case 1: all on a line
    rofn(i, cyc.size()) {
        int u = cyc[i];
        T3 mx = t3val[u];
        if (i != cyc.size()-1)
            mx.setmax(dp[i+1]);
        dp[i] = mx.a + mx.b + val[u];
        setmax(ans, mx.a + mx.b + mx.c + val[u]);
    }

    // case 2: on back edge
    int sum = 0;
    rofn(i, cyc.size()) {
        int u = cyc[i];
        sum += val[u] + t3val[u].a;
        dp[i] = max(dp[i+1], sum + t3val[u].b);
    }
    sum = 0;
    forn(i, cyc.size()) {
        int u = cyc[i];
        sum += val[u] + t3val[u].a;
        setmax(ans, sum + t3val[u].b + dp[i+1]);
    }
    W(ans);
    
    return 0;
}