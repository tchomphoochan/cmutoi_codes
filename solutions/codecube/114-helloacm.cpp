#include <cstdio>
#include <cmath>
#include <algorithm>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {

        int a, b, m, ans;
        scanf("%d%d", &a, &b);
        m = std::min(a, b);

        if (a >= b)
            ans = b/20 + 1;
        else
            ans = floor((a-20+(b%20 == 0 ? 20 : b%20) - b%20) / 20.0) + 1;

        printf("Case #%d: %d\n", i, ans);

    }
    return 0;
}