#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) begin(x), end(x)
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define forx(i, a, b) for (int i = (a); i <= (b); ++i)
#define rofn(i, n) for (int i = (n)-1; i >= 0; --i)
#define rof1(i, n) for (int i = (n); i > 0; --i)
#define rofx(i, a, b) for (int i = (a); i >= (b); --i)

const int seed = 31415926;

mt19937 rnd(seed);
struct item {
    int key, val, mx, prio;
    item *l, *r;
    item(int k, int v) : key(k), val(v), mx(v), prio(rnd()), l(NULL), r(NULL) {}
};
using pitem = item*;
int gmax(pitem x) { return x ? x->mx : 0; }
void upd(pitem x) { if (x) x->mx = max(max(gmax(x->l), gmax(x->r)), x->val); }

void split(pitem t, int x, pitem &l, pitem &r) {
    if (!t) l = r = NULL;
    else if (x < t->key) split(t->l, x, l, t->l), r = t;
    else split(t->r, x, t->r, r), l = t;
    upd(t);
}

void merge(pitem &t, pitem l, pitem r) {
    if (!l || !r) t = l ? l : r;
    else if (l->prio > r->prio) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    upd(t);
}

void modify(pitem &t, int k, int v, int q) {
    pitem t1, t2, t3;
    split(t, k-1, t1, t2);
    split(t2, k, t2, t3);
    if (t2 == NULL) t2 = new item(k, 0);
    if (q == 0) t2->val = max(t2->val, v);
    else t2->val += v;
    upd(t2);
    merge(t, t1, t2);
    merge(t, t, t3);
}

#define fora(x, v) for (auto x : v)
#define pb push_back

const int N = 100010;

vector<int> G[N];
int val[N], par[N], deg[N];
pitem tr[N];

void loopadd(pitem &d, pitem &s)
{
    if (!s) return;
    loopadd(d, s->l);
    loopadd(d, s->r);
    modify(d, s->key, s->val, 1);
    delete s;
    s = NULL;
}

void print_tree(pitem t)
{
    if (!t) return;
    printf("(%d, %d)\n", t->key, t->val);
    print_tree(t->l);
    print_tree(t->r);
}

void dfs(int u)
{
    int ans = 1;
    fora(v, G[u]) {
        dfs(v);
        pitem l, r;
        split(tr[v], val[u], l, r);
        ans += gmax(l);
        loopadd(tr[u], l);
        loopadd(tr[u], r);
        tr[v] = NULL;
    }
    modify(tr[u], val[u], ans, 0);
    printf("\nAt u = %d\n", u);
    print_tree(tr[u]);
    printf("gmax(%d) = %d\n", u, gmax(tr[u]));
}

int main()
{
    int n;
    scanf("%d", &n);
    forn(i, n) scanf("%d", &val[i]);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
    }
    dfs(0);
    printf("%d\n", n - gmax(tr[0]));
    
    return 0;
}