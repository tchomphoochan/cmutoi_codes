#include <cstdio>

#define N 100010

typedef long long ll;

int n;
int arr[N];
ll cnt[N], qs[N];

ll calc(int b, ll ft[])
{
    ll sum = 0;
    while (b != 0) {
        sum += ft[b];
        b -= b & -b;
    }
    return sum;
}

void add(int i, int x, ll ft[])
{
    while (i <= 100001) {
        ft[i] += x;
        i += i & -i;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        arr[b] = a;
    }

    add(arr[n], 1, cnt);
    add(arr[n], arr[n], qs);
    ll ans = 0;
    for (int i = n-1; i >= 1; --i) {
        ans += calc(arr[i]-1, cnt) * arr[i] + calc(arr[i]-1, qs);
        add(arr[i], 1, cnt);
        add(arr[i], arr[i], qs);
    }

    printf("%lld", ans);
}