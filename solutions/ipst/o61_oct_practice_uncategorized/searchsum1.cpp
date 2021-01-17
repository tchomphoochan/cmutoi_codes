#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

int arr[N];
ll qs[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        qs[i] = qs[i-1] + arr[i];
    }

    while (m--) {
        ll x;
        scanf("%lld", &x);
        int cnt = upper_bound(qs, qs+n+1, x)-1 - qs;
        printf("%d\n", cnt);
    }

    return 0;
}