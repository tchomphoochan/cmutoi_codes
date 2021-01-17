#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int T = 1; T <= 10; ++T) {

        int n, k;
        scanf("%d%d", &n, &k);

        --k;
        int lim = n*(n+1)/2 - 1;
        
        if (abs(k) > lim || abs(k) == lim-2 || (k%2+2)%2 != lim%2) {
            printf("Impossible\n");
            continue;
        }

        int tt = (n+2)*(n-1)/2;
        int x = (tt-abs(k))/2;
        bool sign[3010] = {};
        for (int i = n; i >= 2 && x >= 0; --i) {
            if (x-i >= 0) {
                x -= i;
                sign[i] = true;
            }
        }
        if (x > 0) {
            x = (tt-abs(k))/2;
            fill(sign, sign+3010, false);
            for (int i = n-1; i >= 2 && x >= 0; --i) {
                if (x-i >= 0) {
                    x -= i;
                    sign[i] = true;
                }
            }
        }
        printf("1");
        for (int i = 2; i <= n; ++i) {
            if (sign[i] == k > 0)
                printf("-");
            else
                printf("+");
            printf("%d", i);
        }
        printf("\n");

    }

    return 0;
}