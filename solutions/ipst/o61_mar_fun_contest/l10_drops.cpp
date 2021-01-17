#include <bits/stdc++.h>

const int N = 10010;
int cnt[N];

int main()
{
    int h, l, n;
    scanf("%d%d%d", &h, &l, &n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x >= l && x <= l+h)
            mx = std::max(mx, ++cnt[x]);
    }
    printf("%d\n", mx);
    
    return 0;
}