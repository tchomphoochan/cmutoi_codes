#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int arr[N], dp[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    sort(arr, arr+n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[i]%arr[j] == 0)
                dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    
    printf("%d\n", ans);

    return 0;
}
