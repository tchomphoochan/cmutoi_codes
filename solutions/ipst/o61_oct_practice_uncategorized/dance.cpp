#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 100010;
const int INF = 1e9;

int n;
int a[N], b[N], h[N], k[N], cnt[N];
pii splus[N<<1], sminus[N<<1];

void build()
{
    for (int i = 0; i < n; ++i) {
        splus[n+i] = {b[i]+k[i], i};
        sminus[n+i] = {b[i]-k[i], i};
    }
    for (int i = n-1; i > 0; --i) {
        splus[i] = max(splus[i<<1], splus[i<<1|1]);
        sminus[i] = max(sminus[i<<1], sminus[i<<1|1]);
    }
}

pii query(pii seg[], int l, int r)
{
    pii ans = {-INF, 0};
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans = max(ans, seg[l++]);
        if (r&1) ans = max(ans, seg[--r]);
    }
    return ans;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d%d", &h[i], &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &k[i], &b[i]);
    build();

    for (int i = 0; i < n; ++i) {
        int mid = lower_bound(k, k+n, h[i]) - k;
        int j1 = query(splus, 0, mid).second;
        int j2 = query(sminus, mid, n).second;
        int ans1 = a[i]+b[j1]-abs(h[i]-k[j1]);
        int ans2 = a[i]+b[j2]-abs(h[i]-k[j2]);
        printf("%d\n", max(ans1, ans2));
    }

    return 0;
}