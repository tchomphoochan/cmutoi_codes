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

#define pb push_back

const int N = 1010;
const int INF = 1e9;

vector<int> G[N];
pii E[N*10];
pii mne(INF, -1);

int s, tick=0, dep[N], in[N], out[N];

void dfs(int u, int p)
{
    //printf("dfs(%d, %d)\n", u, p);
    dep[u] = dep[p]+1;
    in[u] = out[u] = ++tick;
    for (auto v : G[u]) {
        if (v == p) continue;
        if (v == s) {
            printf("%d %d %d\n", u, v, 0);
        } else if (!in[v]) {
            printf("%d %d %d\n", u, v, 0);
            dfs(v, u);
        } else if (dep[u] == dep[v]) {
            if (in[u] < in[v])
                printf("%d %d %d\n", u, v, 0);
        } else {
            if (dep[u] < dep[v])
                printf("%d %d %d\n", u, v, 0);
        }
    }
    //printf("out of dfs(%d, %d)\n", u, p);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].pb(v);
        G[v].pb(u);
        E[i] = pii(u, v);
        mne = min(mne, pii(w, i));
    }
    printf("%d %d\n", mne.F, 1);
    s = E[mne.S].S;
    printf("%d %d %d\n", s, E[mne.S].F, 1);
    dfs(E[mne.S].F, s);
    
    return 0;
}