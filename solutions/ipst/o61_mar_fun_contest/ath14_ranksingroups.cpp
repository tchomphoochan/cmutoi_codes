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

const int N = 100010;

struct item {
    int key, prio, cnt;
    item *l, *r;
    item() {}
    item(int key, int prio) : key(key), prio(prio), cnt(1), l(NULL), r(NULL) { }
};
typedef item* pitem;
int cnt(pitem t) { return t ? t->cnt : 0; }
int upd_cnt(pitem &t) { if (t) t->cnt = 1+cnt(t->l)+cnt(t->r); }

pitem at[N];
int parent[N];
int root(int u) {
    if (parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}

void split(pitem t, int key, pitem &l, pitem &r)
{
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split(t->l, key, l, t->l), r = t;
    else
        split(t->r, key, t->r, r), l = t;
    upd_cnt(t);
}

void merge(pitem &t, pitem l, pitem r)
{
    if (!l || !r)
        t = l ? l : r;
    else if (l->prio > r->prio)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd_cnt(t);
}

void insert(pitem &t, pitem x)
{
    if (!t)
        t = x;
    else if (x->prio > t->prio)
        split(t, x->key, x->l, x->r), t = x;
    else
        insert(x->key < t->key ? t->l : t->r, x);
    upd_cnt(t);
}

pitem unite(pitem l, pitem r)
{
    if (!l || !r) return l ? l : r;
    if (l->prio < r->prio) swap(l, r);
    pitem lt, rt;
    split(r, l->key, lt, rt);
    l->l = unite(l->l, lt);
    l->r = unite(l->r, rt);
    upd_cnt(l);
    return l;
}

int getrank(pitem t, int key)
{
    if (key == t->key)
        return cnt(t->l)+1;
    else if (key < t->key)
        return getrank(t->l, key);
    else
        return cnt(t->l)+1+getrank(t->r, key);
}

int program()
{
    int T;
    R(T);
    while (T--) {
        int n, m;
        R(n, m);
        set<int> used;
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            at[i] = NULL;
            int prio;
            do {
                prio = r32.next();
            } while (used.count(prio));
            used.insert(prio);
            insert(at[i], new item(i, prio));
        }
        while (m--) {
            int t, x, y;
            R(t);
            if (t==1) {
                R(x, y);
                x = root(x), y = root(y);
                at[x] = unite(at[x], at[y]);
                parent[y] = x;
            } else {
                R(x);
                W(cnt(at[root(x)]) - getrank(at[root(x)], x) + 1);
            }
        }
    }
    
    return 0;
}