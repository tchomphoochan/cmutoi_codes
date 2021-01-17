#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const ll INF = 1e18;

int arr[N];

int main()
{
    // I LOVE TIME LIMIT </3

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        ll ans = -INF, b = -INF;
        for (int i = l; i <= r; ++i) {
            b = max(b+arr[i], arr[i]*1LL);
            ans = max(ans, b);
        }
        printf("%lld\n", max(ans, 0LL));
    }

    return 0;
}