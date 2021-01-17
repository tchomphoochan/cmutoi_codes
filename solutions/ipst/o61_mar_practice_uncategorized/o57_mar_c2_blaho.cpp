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
    ios::sync_with_stdio(false), cin.tie(0);
    //time_t begin = clock();
    int ret = program();
    //time_t end = clock();
    //fprintf(stderr, "Program took %.3f seconds to compute\n", ((double)end-begin)/CLOCKS_PER_SEC);
    return ret;
}

/************************************************************
                CODE STARTS BELOW THIS POINT
************************************************************/

const int N = 10010;

int n, m;
string chr;
vector<int> g[N];

int cnt, cmp[N];
set<int> G[N];
string str[N];

stack<int> S;
bool chk[N];
int d[N], low[N], tick;

string dp[N];

void scc(int u)
{
    d[u] = low[u] = ++tick;
    chk[u] = true;
    S.push(u);
    for (auto v : g[u]) {
        if (!d[v]) {
            scc(v);
            setmin(low[u], low[v]);
        } else if (chk[v]) {
            setmin(low[u], d[v]);
        }
    }
    if (low[u] == d[u]) {
        ++cnt;
        int v;
        do {
            v = S.top();
            S.pop();
            chk[v] = false;
            cmp[v] = cnt;
        } while (v != u);
    }
}

int program()
{
    cin >> n >> m >> chr;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    for1(u, n) if (!d[u]) scc(u);
    for1(u, n) {
        str[cmp[u]].pb(chr[u-1]);
        for (auto v : g[u]) {
            if (cmp[u] != cmp[v])
                G[cmp[u]].insert(cmp[v]);
        }
    }

    chk[cmp[n]] = true;
    for1(u, cnt) {
        sort(str[u].begin(), str[u].end());
        string mx = "";
        for (auto v : G[u]) {
            if (chk[v]) {
                chk[u] = true;
                if (dp[v].size() > mx.size()) mx = dp[v];
                else if (dp[v].size() == mx.size()) setmin(mx, dp[v]);
            }
        }
        dp[u] = chk[u] ? str[u]+mx : "";
    }
    cout << dp[cmp[1]] << endl;
    
    return 0;
}