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

const int N = 1010;

vector<int> cant[N];
bool done[N];
int val[N];
int tb[N][N];

int main()
{
    int n0, m, k;
    scanf("%d%d%d", &n0, &m, &k);
    int n = max(n0, m);
    forn(i, k) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        b -= c-1;
        while (b <= 0) b += n;
        cant[b].pb(a);
    }
    for1(i, n) {
        int j = i%n+1;
        fora(x, cant[i]) {
            while (val[j] != 0)
                j = j%n+1;
            val[j] = x;
            done[x] = true;
        }
    }
    for1(i, n) {
        fora(x, cant[i]) {
            if (x == val[i]) {
                printf("0\n");
                while (true); // LET IT TIME OUT YAY <3
            }
        }
    }
    for1(i, n) if (!done[i]) {
        for1(j, n) if (val[j] == 0) {
            val[j] = i;
            break;
        }
    }
    for1(i, n)
        tb[i][1] = val[i];
    forx(j, 2, n) {
        tb[1][j] = tb[n][j-1];
        forx(i, 2, n) tb[i][j] = tb[i-1][j-1];
    }
    printf("%d\n", n);
    for1(j, n) {
        vector<pii> add;
        for1(i, m) {
            if (tb[i][j] <= n0)
                add.eb(tb[i][j], i);
        }
        printf("%d", add.size());
        fora(p, add)
            printf(" %d %d", p.F, p.S);
        printf("\n");
    }

    return 0;
}