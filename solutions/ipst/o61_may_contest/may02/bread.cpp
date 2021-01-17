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
#define fora(x, v) for (auto x : v)
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)

const int N = 1<<18;

int n;
int tag[N<<1], score[N<<1], A[N];
vector<int> has[N];
int seq[N];

void update(int l, int r, int x, int p=1, int b=0, int e=n-1)
{
    /*if (b == 0 && e == n-1)
        printf("Add %d to range (%d, %d)\n", x, l, r);*/
    if (b > r || e < l)
        return;
    if (b >= l && e <= r) {
        tag[p] += x;
    } else {
        int m = (b+e)/2;
        update(l, r, x, p<<1, b, m);
        update(l, r, x, p<<1|1, m+1, e);
    }
    if (tag[p] != 0) score[p] = e-b+1;
    else score[p] = b == e ? 0 : score[p<<1] + score[p<<1|1];
}

int main()
{
    scanf("%d", &n);
    assert(n >= 1);
    assert(n <= 100000);
    forn(i, n) {
        scanf("%d", &A[i]);
        assert(A[i] >= 0);
        assert(A[i] <= n-1);
        has[A[i]].pb(i);
    }
    forn(i, n) {
        forn(j, has[i].size())
            seq[has[i][j]] = j;
        has[i].pb(n);
        if (has[i].size() > 5)
            update(has[i][4], has[i][5]-1, 1);
    }
    /*forn(i, n)
        printf("%d ", seq[i]);
    printf("\n");*/
    ll ans = score[1];
    forn(i, n) {
        //printf("At i = %d, A[i] = %d\n", i, A[i]);
        if (seq[i]+5 < has[A[i]].size()) {
            int b = has[A[i]][seq[i]+4];
            int m = has[A[i]][seq[i]+5];
            update(b, m-1, -1);
            if (m != n) {
                int e = has[A[i]][seq[i]+6];
                update(m, e-1, 1);
            }
        }
        ans += score[1];
    }
    printf("%lld\n", ans);

    return 0;
}