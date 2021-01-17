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
// loops
#define forx(i, x, y) for (int i = (x); i <= (y); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rofx(i, x, y) for (int i = x; i >= y; --i)
#define rofn(i, n) for (int i = n-1; i >= 0; --i)
#define rof1(i, n) for (int i = n; i >= 1; --i)
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

struct Data {
    int i, j, k, d;
    bool operator<(const Data &rhs) const {
        return d > rhs.d;
    }
};

const int N = 310;
const int INF = 1e9;
int n, m, val[N][N];
priority_queue<Data> Q;
int dist[N][N][16];
bool chk[N][N][16], vis[N][N];

inline bool bound(int i, int j) { return i >= 0 && i <= n+1 && j >= 0 && j <= m+1; }

void fillval(int i, int j, int x=0)
{
    if (!bound(i, j) || val[i][j] != 0 || vis[i][j])
        return;
    vis[i][j] = true;
    if (x == 0)
        val[i][j] = INF;
    else
        Q.push({i, j, 1<<(x-1), 0});
    fillval(i-1, j, x);
    fillval(i+1, j, x);
    fillval(i, j-1, x);
    fillval(i, j+1, x);
}

int program()
{
    // receive input
    R(n, m);
    for1(i, n) for1(j, m) R(val[i][j]);

    // fill outside boundary with infinity
    fillval(0, 0);
    for1(i, n) for1(j, m)
        if (val[i-1][j] == INF || val[i+1][j] == INF || val[i][j-1] == INF || val[i][j+1] == INF)
            setmax(val[i][j], INF-1);
    for1(i, n) for1(j, m)
        if (val[i][j] == INF-1)
            val[i][j] = INF;
    
    // identify ponds and find shortest path starting source 
    int cnt = 0;
    for1(i, n) for1(j, m) {
        if (val[i][j] == 0 && !vis[i][j])
            fillval(i, j, ++cnt);
    }
    if (cnt <= 1) {
        W(0);
        return 0;
    }
    int pass = (1<<cnt)-1;

    /*for1(i, n) { for1(j, m)
        if (val[i][j] == INF) printf("# ");
        else printf("%d ", val[i][j]);
        printf("\n");
    }*/

    for1(i, n) for1(j, m) forn(k, pass+1)
        if (k == 0) dist[i][j][k] = val[i][j];
        else dist[i][j][k] = INF;

    while (!Q.empty()) {
        auto u = Q.top();
        Q.pop();
        int i = u.i, j = u.j, k = u.k, d = u.d;
        if (chk[i][j][k])
            continue;
        //W("at", i, j, k, d);
        chk[i][j][k] = true;
        if (k == pass) {
            W(d);
            break;
        }
        pii way[] = {
            {i-1, j},
            {i+1, j},
            {i, j-1},
            {i, j+1}
        };
        for (auto w : way) {
            for (int h = 0; h <= pass; ++h) {
                Data v = {w.F, w.S, k|h, d+dist[w.F][w.S][h]};
                if (val[v.i][v.j] != INF && !chk[v.i][v.j][v.k]
                && setmin(dist[v.i][v.j][v.k], v.d)) {
                    //W("push ", v.i, v.j, v.k, v.d);
                    Q.push(v);
                }
            }
        }
        /*Data vs[] = {
            {i-1, j, k, d+val[i-1][j]},
            {i+1, j, k, d+val[i+1][j]},
            {i, j-1, k, d+val[i][j-1]},
            {i, j+1, k, d+val[i][j+1]}
        };
        for (auto v : vs) {
            if (val[v.i][v.j] != INF && !chk[v.i][v.j][v.k]
            && setmin(dist[v.i][v.j][v.k], v.d)) {
                W("push ", v.i, v.j, v.k, v.d);
                Q.push(v);
            }
        }*/
        //W("-----------");
    }

    return 0;
}
