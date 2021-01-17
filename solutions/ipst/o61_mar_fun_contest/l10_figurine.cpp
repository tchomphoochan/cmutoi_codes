#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 150010;

int arr[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n, greater<int>());
    int r = n/5;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i%2 != 0 && r)
            --r;
        else
            ans += arr[i];
    }
    printf("%lld\n", ans);

    return 0;
}