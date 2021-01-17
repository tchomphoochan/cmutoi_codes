#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int cnt[N];
map<int,int> rem;

int cbit(int x, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if ((1<<i)&x)
            ++cnt;
    }
    return cnt;
}

void solve(int cn)
{
    int n, k;
    scanf("%d%d", &n, &k);
    if (n == 0) exit(0);
    for (int i = 0; i < n; ++i)
        scanf("%d", &cnt[n-1-i]);
    
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        int p = 0;
        for (int j = 0; j < t; ++j) {
            int x;
            scanf("%d", &x);
            --x;
            p |= 1<<(n-1-x);
        }
        int y;
        scanf("%d", &y);
        rem[p] = y;
    }

    int mxi, mxv = 0;
    for (int i = 1; i < (1<<n); ++i) {
        if (cbit(i, n) != k)
            continue;
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (i&(1<<j))
                ans += cnt[j];
        }
        for (auto xy : rem) {
            int x, y;
            tie(x, y) = xy;
            ans -= max((cbit(x&i, n)-1), 0)*(y);
        }
        if (ans >= mxv) {
            mxi = i;
            mxv = ans;
        }
    }

    printf("Case Number  %d\n", cn);
    printf("Number of Customers: %d\n", mxv);
    printf("Locations recommended:");
    int pnt = 0;
    for (int i = n-1; i >= 0; --i) {
        if ((1<<i)&mxi) {
            printf(" %d", n-i);
        }
    }
    printf("\n\n");
}

int main()
{
    for (int i = 1; ; ++i) {
        fill(cnt, cnt+N, 0);
        rem.clear();
        solve(i);
    }
    return 0;
}