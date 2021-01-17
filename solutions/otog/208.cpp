#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000010;

ll arr[N], qs[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &arr[i]);
        qs[i] = qs[i-1] + arr[i];
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld\n", qs[b]-qs[a-1]);
    }

    return 0;
}