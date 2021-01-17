#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define F first
#define S second
#define forx(i, x, y) for (int i = (x); i <= (y); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rofx(i, x, y) for (int i = x; i >= y; --i)
#define rofn(i, n) for (int i = n-1; i >= 0; --i)
#define rof1(i, n) for (int i = n; i >= 1; --i)
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define fora(x, v) for (auto x : v)

struct Event
{
    int type; // 0 = add, 1 = query, 2 = remove
    int tim; // time
    int v1; // location
    int v2; // query index or building type
    bool operator<(const Event &rhs) const {
        if (tim != rhs.tim) return tim < rhs.tim;
        if (type != rhs.type) return type < rhs.type;
        if (v1 != rhs.v1) v1 < rhs.v1;
        return v2 < rhs.v2;
    }
};

const int N = 6e5+10;

vector<Event> events;
int ans[N];

vector<int> coor;
int c;
struct node {
    int sum;
    node *l, *r;
    node(int s) : sum(s), l(NULL), r(NULL) {}
    node(node *l, node *r) : l(l), r(r), sum(l->sum + r->sum) {}
};
node *root[N];

int found[N];

node *build(int b=1, int e=c)
{
    if (b == e)
        return new node(0);
    int m = (b+e)/2;
    return new node(build(b, m), build(m+1, e));
}

int query(int l, int r, node *p, int b=1, int e=c)
{
    if (b >= l && e <= r)
        return p->sum;
    if (b > r || e < l)
        return 0;
    int m = (b+e)/2;
    return query(l, r, p->l, b, m) + query(l, r, p->r, m+1, e);
}

node *update(int i, int x, node *p, int b=1, int e=c)
{
    if (b == e)
        return new node(p->sum + x);
    int m = (b+e)/2;
    if (i <= m)
        return new node(update(i, x, p->l, b, m), p->r);
    else
        return new node(p->l, update(i, x, p->r, m+1, e));
}

int main()
{
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);

    bool skip = false;
    // subtask 1, 2
    if (k <= 400 && !skip) {

        forn(i, n) {
            int x, t, a, b;
            scanf("%d%d%d%d", &x, &t, &a, &b);
            events.pb({0, a, x, t});
            events.pb({2, b, x, t});
        }
        forn(i, q) {
            int l, y;
            scanf("%d%d", &l, &y);
            events.pb({1, y, l, i});
        }
        sort(all(events));

        vector<multiset<int>> pos(k+1, multiset<int>());
        for1(i, k) {
            pos[i].insert(-1e9);
            pos[i].insert(1e9);
        }
        fora(e, events) {
            if (e.type == 0) { // add
                pos[e.v2].insert(e.v1);
            } else if (e.type == 1) { // answer query

                int a = 0;
                for1(i, k) {
                    auto r = pos[i].lower_bound(e.v1);
                    auto l = prev(r);
                    a = max(a, min(abs(*l-e.v1), abs(*r-e.v1)));
                }
                if (a > 1e8)
                    a = -1;
                ans[e.v2] = a;

            } else { // remove
                pos[e.v2].erase(pos[e.v2].find(e.v1));
            }
        }

        forn(i, q)
            printf("%d\n", ans[i]);

    } else { // subtask 3

        vector<pii> st; // stores (position, type)
        forn(i, n) {
            int x, t, a, b;
            scanf("%d%d%d%d", &x, &t, &a, &b);
            st.pb({x, t});
            coor.pb(x);
        }
        sort(all(st));
        sort(all(coor));
        coor.resize(unique(all(coor))-coor.begin());
        c = coor.size();

        for1(i, n) root[i] = NULL;
        root[0] = build();
        fora(at, st) {
            int x = at.F, t = at.S;
            int p = lower_bound(all(coor), x) - coor.begin() + 1;
            root[p] = root[p-1];
            if (found[t] == 0)
                root[p] = update(found[t], -1, root[p]);
            found[t] = p;
            root[p] = update(p, 1, root[p]);
        }
        
        forn(i, q) {
            int x, y;
            scanf("%d%d", &x, &y);
            //printf("\nquery %d\n", x);
            int b = 0;
            int e = 1e8;
            while (b < e) {
                int m = (b+e)/2;
                int lp = lower_bound(all(coor), x-m) - coor.begin() + 1;
                int rp = upper_bound(all(coor), x+m)-1 - coor.begin() + 1;
                //printf("try m=%d, l=%d (%d), r=%d (%d)", m, x-m, lp, x+m, rp);
                int q = query(lp, rp, root[rp]);
                //printf("got %d\n", q);
                if (q == k)
                    e = m;
                else
                    b = m+1;
            }
            if (b > 1e8) b = -1;
            printf("%d\n", b);
        }

    }

    return 0;
}