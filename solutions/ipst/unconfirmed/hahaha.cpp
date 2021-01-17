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

struct item {
    int cnt[6], val;
    ll inver;
    int prio;
    item *l, *r;
    bool rev;
    int sett;
    item(int v) {
        forn(i, 6) cnt[i] = 0;
        cnt[0] = cnt[v] = 1;
        val = v;
        inver = 0;
        prio = r32();
        l = r = NULL;
        rev = false;
        sett = 0;
    }
};
using pitem = item*;

int cnt(pitem t, int i=0) { return t ? t->cnt[i] : 0; }
ll inver(pitem t) { return t ? t->inver : 0; }
void push(pitem &t) {
    if (!t) return;
    if (t->sett) {
        t->val = t->sett;
        t->inver = 0;
        for1(i, 5) t->cnt[i] = 0;
        t->cnt[t->val] = t->cnt[0];

        if (t->l) t->l->sett = t->sett;
        if (t->r) t->r->sett = t->sett;
        t->sett = 0;
        t->rev = false;
    } else if (t->rev) {
        ll ni = ((ll)t->cnt[0]*(t->cnt[0]-1))/2 - t->inver;
        for1(i, 5) ni -= ((ll)t->cnt[i]*(t->cnt[i]-1))/2;
        t->inver = ni;

        if (t->l) t->l->rev ^= true;
        if (t->r) t->r->rev ^= true;
        swap(t->l, t->r);
        t->rev = false;
    }
}
void upd(pitem &t) {
    if (!t) return;
    push(t->l), push(t->r);
    forn(i, 6) t->cnt[i] = cnt(t->l, i) + cnt(t->r, i);
    ++t->cnt[0];
    ++t->cnt[t->val];
    t->inver = inver(t->l) + inver(t->r);
    for1(i, 5) for1(j, i-1)
        t->inver += (ll)cnt(t->l, i)*cnt(t->r, j);
    forx(i, t->val+1, 5)
        t->inver += cnt(t->l, i);
    forx(i, 1, t->val-1)
        t->inver += cnt(t->r, i);
}

void split(pitem t, int x, pitem &l, pitem &r)
{
    push(t);
    if (!t)
        l = r = NULL;
    else if (cnt(t->l) >= x)
        split(t->l, x, l, t->l), r = t;
    else
        split(t->r, x-cnt(t->l)-1, t->r, r), l = t;
    upd(t);
}

void merge(pitem &t, pitem l, pitem r)
{
    push(l);
    push(r);
    if (!l || ! r)
        return void(t = l ? l : r);
    if (l->prio > r->prio)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd(t);
}

void split3(pitem t, int a, int b, pitem &t1, pitem &t2, pitem &t3)
{
    split(t, b, t2, t3);
    split(t2, a-1, t1, t2);
}

void merge3(pitem &t, pitem t1, pitem t2, pitem t3)
{
    merge(t, t1, t2);
    merge(t, t, t3);
}

const int N = 100010;

pitem root = 0;
char s[N];

int _main()
{
    int n, m;
    scanf("%d%d %s", &n, &m, s);
    forn(i, n)
        merge(root, root, new item(s[i]-'0'+1));

    while (m--) {
        int t, a, b, c;
        R(t, a, b);
        if (t == 1) {
            R(c);
            ++c;
            pitem t1, t2, t3;
            split3(root, a, b, t1, t2, t3);
            t2->sett = c;
            merge3(root, t1, t2, t3);
        } else if (t == 2) {
            pitem t1, t2, t3;
            split3(root, a, b, t1, t2, t3);
            t2->rev ^= true;
            merge3(root, t1, t2, t3);
        } else if (t == 3) {
            pitem t1, t2, t3;
            split3(root, a, b, t1, t2, t3);
            W(inver(t2));
            merge3(root, t1, t2, t3);
        }
    }
    
    return 0;
}