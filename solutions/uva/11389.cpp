#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 110;

int a[N];
int b[N];

int main()
{
    while (true) {
        int n, d, r;
        scanf("%d%d%d", &n, &d, &r);
        if (n == 0)
            break;

        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &b[i]);
        sort(a, a+n);
        sort(b, b+n, greater<int>());
        ll p = 0;
        for (int i = 0; i < n; ++i) {
            ll s = a[i]+b[i];
            p += max(s-d, 0LL);
        }
        printf("%lld\n", p*r);
    }

    return 0;
}