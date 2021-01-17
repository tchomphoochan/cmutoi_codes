#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define F first
#define S second

pii comb(pii l, pii r)
{
    return pii(
        l.first + max(r.first-l.second, 0),
        r.second + max(l.second-r.first, 0)
    );
}

const int N = 400010;

char s[N];
pii seg[N<<1];

void build(int n)
{
    for (int i = n-1; i > 0; --i)
        seg[i] = comb(seg[i<<1], seg[i<<1|1]);
}

pii query(int n, int l, int r)
{
    pii ansl(0, 0), ansr(0, 0);
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if (l&1) ansl = comb(ansl, seg[l++]);
        if (r&1) ansr = comb(seg[--r], ansr);
    }
    return comb(ansl, ansr);
}

int main()
{
    int n;
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        s[n+i] = s[i];
    for (int i = 0; i < 2*n; ++i)
        seg[i+2*n] = s[i] == '(' ? pii(0, 1) : pii(1, 0);
    build(2*n);
    /*for (int i = 0; i < 4*n; ++i) {
        printf("%d: %d %d\n", i, seg[i].first, seg[i].second);
    }
    return 0;*/

    int m;
    scanf("%d", &m);
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l; --r;
        if (l > r)
            r += n;
        pii x = query(2*n, l, r);
        if (x == pii(0, 0))
            printf("yes\n");
        else
            printf("no\n");
    }
    
    return 0;
}