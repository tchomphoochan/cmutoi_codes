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

const int N = 1e5+10;

int n, m;
char s[N];
int suf[N], rev[N], lcp[N], t[N<<1];
pii rnk[N];

int query(int l, int r) {
    int ans = n;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans = min(ans, t[l++]);
        if (r&1) ans = min(ans, t[--r]);
    }
    return ans;
}

int _main()
{
    R(n, m);
    scanf(" %s", s);
    forn(i, n) suf[i] = i, rnk[i] = {s[i], s[i+1]};
    auto cmp = [&] (int a, int b) {
        return rnk[a] < rnk[b];
    };
    sort(suf, suf+n, cmp);
    forn(i, n) rev[suf[i]] = i;

    for (int z = 4; z <= 4*n; z *= 2) {
        int nr = 0;
        pii prev = rnk[suf[0]];
        rnk[suf[0]].F = nr;
        forx(i, 1, n-1) {
            if (rnk[suf[i]] != prev) ++nr;
            prev = rnk[suf[i]];
            rnk[suf[i]].F = nr;
        }
        forn(i, n) {
            int j = suf[i] + z/2;
            rnk[suf[i]].S = j < n ? rnk[j].F : -1;
        }
        sort(suf, suf+n, cmp);
        forn(i, n) rev[suf[i]] = i;
    }
    int k = 0;
    forn(i, n) {
        if (rev[i] == n-1) {
            k = 0;
            continue;
        }
        int j = suf[rev[i]+1];
        while (i+k < n && j+k < n && s[i+k] == s[j+k]) ++k;
        lcp[rev[i]] = k;
        if (k > 0) --k;
    }
    forn(i, n) t[i+n] = lcp[i];
    rofx(i, n-1, 1) t[i] = min(t[i<<1], t[i<<1|1]);
    //forn(i, n) W(lcp[i], &s[suf[i]]);

    set<int> has;
    has.insert(rev[0]);
    while (m--) {
        int t, x;
        R(t, x); --x;
        if (t == 1) has.insert(rev[x]); else {
            int i = rev[x];
            int ans = has.count(i) ? n-x : 0;
            auto l = has.lower_bound(i);
            auto r = has.upper_bound(i);
            if (l != has.begin()) setmax(ans, query(*(--l), i-1));
            if (r != has.end()) setmax(ans, query(i, (*r)-1));
            W(ans);
        }
    }
    
    return 0;
}