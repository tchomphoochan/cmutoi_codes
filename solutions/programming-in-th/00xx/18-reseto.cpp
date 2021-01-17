#include <stdio.h>

int cut[1010];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; ++i) {
        if (cut[i])
            continue;
        for (int j = i; j <= n; j += i) {
            if (!cut[j]) {
                cut[j] = 1;
                if (--k == 0) {
                    printf("%d\n", j);
                    return 0;
                }
            }
        }
    }

    return 0;
}