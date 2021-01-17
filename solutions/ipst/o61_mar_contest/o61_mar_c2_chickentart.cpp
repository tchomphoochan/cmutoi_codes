#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define forx(i, a, b) for (int i = (a); i <= (b); ++i)
#define fora(x, v) for (auto x : v)

const int N = 1e5+10;
const ll INF = 1e18;

int n, m, k, A[N];
ll dpl[N], dpr[N];

void conleft(ll lim)
{
    ll cnt = 0, st = 1, sum = INF;
    for1(i, n) {
        if (cnt != INF) {
            if (sum + A[i] > lim || i - st >= m) {
                ++cnt;
                st = i;
                sum = A[i];
                if (A[i] > lim)
                    cnt = INF;
            } else {
                sum += A[i];
            }
        }
        dpl[i] = cnt;
    }
}

void conright(ll lim)
{
    ll cnt = 0, st = n, sum = INF;
    for (int i = n; i >= 1; --i) {
        if (cnt != INF) {
            if (sum + A[i] > lim || st - i >= m) {
                ++cnt;
                st = i;
                sum = A[i];
                if (A[i] > lim)
                    cnt = INF;
            } else {
                sum += A[i];
            }
        }
        dpr[i] = cnt;
    }
}

bool check(ll lim)
{
    conleft(lim);
    conright(lim);

    /*printf("Checking lim = %d\n", lim);
    for1(i, n)
        printf("%d ", dpl[i]);
    printf("\n");
    for1(i, n)
        printf("%d ", dpr[i]);
    printf("\n");*/

    int pa = min(m, n-k+1);
    for1(i, n-pa+1) {
        int j = i+pa-1;
        if (dpl[i-1] + dpr[j+1] <= k-1) {
            //printf("true at %d %d\n", i, j);
            return true;
        }
    }
    //printf("False\n");
    return false;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for1(i, n) scanf("%d", &A[i]);

    ll b = 0;
    ll e = INF;
    while (b < e) {
        ll mid = (b+e)/2;
        if (check(mid))
            e = mid;
        else
            b = mid+1;
    }
    printf("%lld\n", e);

    return 0;
}