#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int arr[N], dp[N], lis[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    arr[0] = 1e9;
    
    int len = 1;
    dp[1] = 1;
    lis[1] = arr[1];
    for (int i = 2; i <= n; ++i) {
        if (arr[i] < lis[1]) {
            dp[i] = 1;
            lis[1] = arr[i];
        } else if (arr[i] > lis[len]) {
            lis[++len] = arr[i];
            dp[i] = len;
        } else {
            int ix = lower_bound(lis+1, lis+len+1, arr[i]) - lis;
            lis[ix] = arr[i];
            dp[i] = ix;
        }
    }

    len = 1;
    lis[1] = arr[n];
    int ans = max(dp[n], dp[n-1]+(arr[n]<arr[n-1]?1:0));
    for (int i = n-1; i >= 1; --i) {
        if (arr[i] < lis[1]) {
            lis[1] = arr[i];
        } else if (arr[i] > lis[len]) {
            lis[++len] = arr[i];
        } else {
            int ix = lower_bound(lis+1, lis+len+1, arr[i]) - lis;
            lis[ix] = arr[i];
        }
        int got = lower_bound(lis+1, lis+len+1, arr[i-1])-1 - lis;
        ans = max(ans, dp[i-1]+got);
    }

    printf("%d", ans);
    return 0;
}