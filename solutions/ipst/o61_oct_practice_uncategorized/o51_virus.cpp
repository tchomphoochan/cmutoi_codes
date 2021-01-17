#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], b[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+n, greater<int>());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, min(a[i], b[i]));
    }
    printf("%d", ans);

    return 0;
}