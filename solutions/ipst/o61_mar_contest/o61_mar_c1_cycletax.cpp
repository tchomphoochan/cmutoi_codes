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

const int INF = 1e9;
const int N = 1010;
const int M = 10010;

pii E[M];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    pii mne(INF, -1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        E[i] = pii(u, v);
        mne = min(mne, pii(w, i));
    }
    printf("%d %d\n", mne.F, 1);
    for (int i = 0; i < m; ++i) {
        int u = E[i].F, v = E[i].S;
        if (i == mne.S) {
            printf("%d %d 1\n", u, v);
        } else if (u == E[mne.S].F) {
            printf("%d %d 0\n", v, u);
        } else if (v == E[mne.S].F) {
            printf("%d %d 0\n", u, v);
        } else if (u == E[mne.S].S) {
            printf("%d %d 0\n", u, v);
        } else if (v == E[mne.S].S) {
            printf("%d %d 0\n", v, u);
        } else {
            if (u > v) swap(u, v);
            printf("%d %d 0\n", u, v);
        }
    }
    
    return 0;
}