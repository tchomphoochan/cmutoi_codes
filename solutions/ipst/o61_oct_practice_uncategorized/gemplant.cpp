#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

int n;
ll ft[N];

ll query(int i)
{
    ll ans = 0;
    for (; i > 0; i -= i&-i)
        ans += ft[i];
    return ans;
}

void update(int i, ll x)
{
    for (; i <= n; i += i&-i)
        ft[i] += x;    
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);

    while (m--) {
        int t, a, b;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &a, &b);
            update(b, a);
        } else {
            scanf("%d%d", &a, &b);
            printf("%lld\n", query(b) - query(a-1));
        }
    }

    return 0;
}