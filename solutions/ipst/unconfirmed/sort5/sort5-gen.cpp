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

/************************************************************
                CODE STARTS BELOW THIS POINT
************************************************************/

using vi = vector<int>;

int n, S;

vector<vi> cellval;

struct Graph {
    vector<vi> mat;
    int val, edge;
    Graph() {
        mat = vector<vi>(n, vi(n, 0));
        val = 0;
        edge = 0;
    }
    Graph add_edge(int u, int v) {
        assert(u != v && !mat[u][v] && !mat[v][u]);
        Graph ret = *this;
        ret.mat[u][v] = 1;
        ret.val += cellval[u][v];
        ++ret.edge;
        return ret;
    }
    Graph transit() {
        Graph ret = *this;
        forn(i, n) ret.mat[i][i] = 1;
        forn(k, n) forn(i, n) forn(j, n)
            if (ret.mat[i][k] == 1 && ret.mat[k][j] == 1)
                ret.mat[i][j] = 1;
        forn(i, n) ret.mat[i][i] = 0;
        ret.val = ret.edge = 0;
        forn(i, n) forn(j, n) if (ret.mat[i][j]) {
            ret.val += cellval[i][j];
            ++ret.edge;
        }
        return ret;
    }
};

struct State { int t, l, r, nl, nr, x; };
vector<int> dp;
vector<State> data;

vector<int> get_topo(Graph G)
{
    vector<int> deg(n);
    forn(i, n) forn(j, n) if (G.mat[i][j]) ++deg[j];
    vector<int> seq;
    queue<int> Q;
    forn(i, n) if (deg[i] == 0) Q.push(i);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        seq.pb(u);
        forn(v, n) if (G.mat[u][v])
            if (--deg[v] == 0) Q.push(v);
    }
    return seq;
}

int solve(Graph G)
{
    if (dp[G.val] != -1)
        return dp[G.val];
    if (G.edge == n*(n-1)/2) {
        vector<int> topo = get_topo(G);
        data[G.val] = {1, topo[0], topo[1], topo[2], topo[3], topo[4]};
        return dp[G.val] = 0;
    }
    dp[G.val] = 1e9;
    forn(u, n) forn(v, n) if (u != v && !G.mat[u][v] && !G.mat[v][u]) {
        Graph gl = G.add_edge(u, v).transit();
        Graph gr = G.add_edge(v, u).transit();
        if (setmin(dp[G.val], max(solve(gl)+1, solve(gr)+1)))
            data[G.val] = {0, u, v, gl.val, gr.val, 0};
    }
    return dp[G.val];
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        W("Requires argument: ./sort5 n");
        return 1;
    }
    n = atoi(argv[1]);
    S = pow(3, n*(n-1)/2);
    cellval = vector<vi>(n, vi(n, 0));
    dp = vector<int>(S, -1);
    data = vector<State>(S);

    int mul = 1;
    forn(i, n) forx(j, i+1, n-1) {
        cellval[i][j] = mul;
        mul *= 3;
    }
    mul = 2;
    forn(j, n) forx(i, j+1, n-1) {
        cellval[i][j] = mul;
        mul *= 3;
    }
    solve(Graph());

    vector<int> states;
    map<int, int> rev;
    forn(i, S) if (dp[i] != -1) {
        states.pb(i);
        rev[i] = states.size()-1;
    }
    printf("struct State { int t, l, r, nl, nr, x; };\n");
    printf("int total_states = %d;\n", states.size());
    printf("State states[] = {");
    forn(i, states.size()) {
        int s = states[i];
        if (i != 0) printf(",");
        if (data[s].t == 1)
            printf("{%d,%d,%d,%d,%d,%d}", data[s].t, data[s].l, data[s].r, data[s].nl, data[s].nr, data[s].x);
        else
            printf("{%d,%d,%d,%d,%d,%d}", data[s].t, data[s].l, data[s].r, rev[data[s].nl], rev[data[s].nr], data[s].x);
    }
    printf("};\n");

    return 0;
}