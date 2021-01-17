#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const int N = 1e6+10;

int n;
ll d;
ll a[N], qs[N];
pli seg[N<<1];
bool printed = false;

pli query(int l, int r)
{
    pli ans = {0, 0};
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans = max(ans, seg[l++]);
        if (r&1) ans = max(seg[--r], ans);
    }
    return ans;
}

void solve(int l, int r)
{
    int m = query(l, r).second;
    if (l <= m-1 && qs[m-1]-(l-1>=0?qs[l-1]:0) >= a[m]-d)
        solve(l, m-1);
    if (printed)
        printf(" ");
    printf("%d", m+1);
    printed = true;
    if (m+1 <= r && qs[r]-qs[m] >= a[m]-d)
        solve(m+1, r);
}

int main()
{
    scanf("%d%lld", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        qs[i] = (i==0 ? 0 : qs[i-1])+a[i];
        seg[n+i] = {a[i], i};
    }
    for (int i = n-1; i > 0; --i)
        seg[i] = max(seg[i<<1], seg[i<<1|1]);
    solve(0, n-1);
    printf("\n");

    return 0;
}
