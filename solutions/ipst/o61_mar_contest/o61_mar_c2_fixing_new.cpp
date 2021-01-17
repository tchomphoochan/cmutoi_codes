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

const int N = 100010;
const int INF = 1e9;

int n, k;
int A[N], D[N];

int main()
{
    scanf("%*d%d%d", &n, &k);
    forn(i, n) {
        scanf("%d", &A[i]);
        if (i > 0) D[i] = A[i]-A[i-1]-1;
    }
    sort(D+1, D+n);
    int sum = 0;
    for1(i, n-k) sum += D[i];
    printf("%d\n", sum);

    return 0;
}