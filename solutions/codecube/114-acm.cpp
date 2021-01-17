#include <cstdio>
#include <cmath>
#include <algorithm>

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {

        int m, n;
        scanf("%d%d", &m, &n);

        int mod = n % 20;
        int low = std::max(0.0, ceil((m-n)/(-20.0)));
        int high = n/20;
        printf("Case #%d: %d\n", t, high-low+1);

    }
    return 0;
}