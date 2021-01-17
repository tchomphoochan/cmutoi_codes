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

const int N = 100010;
const int K = 210;
const int X = 210;
const int Y = 2010;
const int OX = 1;
const int OY = 1001;
const ll INF = 4e18;

ll cnt[X][Y], val[X][Y], cost[X][Y], dp[K][X];

ll calc(int x1, int x2, int y)
{
    ll bot = (cnt[x2][y]-cnt[x1-1][y])*y - (val[x2][y]-val[x1-1][y]);
    ll tops = (val[x2][Y-1]-val[x1-1][Y-1])-(val[x2][y]-val[x1-1][y]);
    ll topc = (cnt[x2][Y-1]-cnt[x1-1][Y-1])-(cnt[x2][y]-cnt[x1-1][y]);
    return bot + tops-y*topc;
}

ll calc2(int x1, int x2)
{
    int b = 1, e = Y-2;
    while (b < e) {
        int m = (b+e)>>1;
        ll v1 = calc(x1, x2, m);
        ll v2 = calc(x1, x2, m+1);
        if (v1 > v2) b = m+1;
        else e = m;
    }
    return calc(x1, x2, b);
}

int _main()
{
    int n, p, w, h;
    R(n, p, w, h);
    forn(i, n) {
        int x, y;
        R(y, x);
        x += OX;
        y += OY;
        ++cnt[x][y];
        val[x][y] += y;
    }
    for1(i, X-1) for1(j, Y-1) {
        cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
        val[i][j] += val[i-1][j] + val[i][j-1] - val[i-1][j-1];
    }
    for1(i, X-1) forx(j, i, X-1)
        cost[i][j] = calc2(i, j);

    p = (p/2)+1;
    ++h;
    forx(k, 0, p) forx(i, 0, h) dp[k][i] = INF;
    dp[0][0] = 0;

    ll ans = INF;
    for1(k, p) for1(i, h) {
        for1(j, i) {
            if (k == 1 || k == p)
                setmin(dp[k][i], dp[k-1][j-1]+calc(j, i, OY));
            else
                setmin(dp[k][i], dp[k-1][j-1]+cost[j][i]);
        }
        setmin(ans, dp[k][h]);
    }
    W(ans);
    
    return 0;
}