#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9+10;
const int N = 1e6+10;

int arr[N], qs[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        qs[i] = qs[i-1] + arr[i];
    }
    int ans = -INF;
    for (int i = k; i <= n; ++i)
        ans = max(ans, qs[i]-qs[i-k]);
    printf("%d\n", ans);
    
    return 0;
}