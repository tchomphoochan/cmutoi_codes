#include <cstdio>
#include <algorithm>

int main()
{
    int n;
    scanf("%d", &n);

    // top row
    printf("-");
    for (int j = 1; j < 2*n+1; ++j)
        printf(" -");
    printf("\n");

    // top part
    for (int i = n-1; i >= 2; --i) {
        printf("-");
        for (int j = 1; j < i; ++j)
            printf(" -");
        for (int j = 0; j < 2*n-2*i+1; ++j)
            printf(" #");
        for (int j = 0; j < i; ++j)
            printf(" -");
        printf("\n");
    }

    // middle
    int l = 1;
    int r = 2*n-3;
    for (int i = 1; i <= n; ++i) {
        printf("- #");
        int m = 2*n-3;
        for (int j = 1; j <= m; ++j) {
            if (j == l || j == r)
                printf(" -");
            else
                printf(" #");
        }
        m = (m+1)/2;
        ++l; --r;
        if (l >= m) {
            l = m;
            r = m;
        }
        printf(" # -\n");
    }

    // bottom part
    for (int i = 2; i <= n-2; ++i) {
        printf("-");
        for (int j = 1; j < i; ++j)
            printf(" -");
        for (int j = 0, m = 2*n-2*i+1; j < m; ++j) {
            if (j == m/2)
                printf(" -");
            else
                printf(" #");
        }
        for (int j = 0; j < i; ++j)
            printf(" -");
        printf("\n");
    }

    // remove
    printf("-");
    for (int j = 1; j < 2*n+1; ++j)
        printf(" -");

    return 0;
}