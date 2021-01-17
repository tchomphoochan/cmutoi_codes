#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int arr[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    
    while (m--) {
        int c;
        scanf("%d", &c);
        int sum = 0;
        int l = 1;
        int ans = 0;
        for (int r = 1; r <= n; ++r) {
            sum += arr[r];
            while (sum > c)
                sum -= arr[l++];
            ans = max(ans, r-l+1);
        }
        printf("%d\n", ans);
    }

    return 0;
}