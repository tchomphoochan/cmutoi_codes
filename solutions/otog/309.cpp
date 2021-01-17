#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 100010;
int arr[N];

int main()
{
    int n;
    scanf("%d", &n);
    int tt = 0;
    int dp = 0, ans = -INF, ans2 = -INF, len = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        tt += arr[i];
        dp = max(dp+arr[i], arr[i]);
        ans = max(ans, dp);
    }
    dp = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp-arr[i] > -arr[i] && len+1 < n) {
            dp = dp-arr[i];
            ++len;
        } else {
            dp = -arr[i];
            len = 1;
        }
        ans2 = max(ans2, dp);
    }
    printf("%d", max(ans, tt+ans2));

    return 0;
}