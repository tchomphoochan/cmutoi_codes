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

const int B = 10010;

int c;
int ft[B][B];
vector<int> c1, c2;

void update(int x0, int y0) {
    ++x0, ++y0;
    for (int x = x0; x <= c1.size(); x += x&-x) {
        for (int y = y0; y > 0; y -= y&-y)
            ++ft[x][y];
    }
}

int query(int x0, int y0) {
    ++x0, ++y0;
    int ans = 0;
    for (int x = x0; x > 0; x -= x&-x) {
        for (int y = y0; y <= c2.size(); y += y&-y)
            ans += ft[x][y];
    }
    return ans;
}

const int N = 100010;

int X[N], H[N];
#define pb push_back

int main()
{
    int n;
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d", &X[i], &H[i]);
        c1.pb(X[i]-H[i]);
        c2.pb(X[i]+H[i]);
    }
    sort(all(c1));
    c1.resize(unique(all(c1)) - c1.begin());
    sort(all(c2));
    c2.resize(unique(all(c2)) - c2.begin());

    forn(i, n) {
        int l = lower_bound(all(c1), X[i]-H[i]) - c1.begin();
        int r = lower_bound(all(c2), X[i]+H[i]) - c2.begin();
        printf("%d\n", query(l, r));
        update(l, r);
    }
    
    return 0;
}