#include <cstdio>
#include <algorithm>

#define INF 1e9

int main()
{
    int n, h[3];
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i)
        scanf("%d", &h[i]);
    
    for (int i = 0; i < n; ++i) {

        int p = i % 3;
        int m = INF;
        for (int j = 0; j < 3; ++j) {
            int d = h[j] - h[p];
            if (d > 0)
                m = std::min(m, d);
        }

        if (m == INF)
            m = 0;
        h[p] += m<<1;

    }

    for (int i = 0; i < 3; ++i)
        printf("%d\n", h[i]);

    return 0;
}