#include <cstdio>

bool can(int n, int s)
{
    return s >= 1 && s <= 9 * n;
}

char ans[100002] = {};

int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    if (n == 1) {
        if (s == 6) {
            printf("6");
            return 0;
        }
    }
    else if (s % 3 == 0) {
        for (int i = 8; i >= 0; i -= 2) {
            if (can(n-1, s-i)) {

                ans[n] = i + '0';
                int cs = i;
                for (int j = n-1; j >= 2; --j) {
                    for (int k = 0; k <= 9; ++k) {
                        if (can(j-1, s - cs - k)) {
                            ans[j] = k + '0';
                            cs += k;
                            break;
                        }
                    }
                }
                ans[1] = s - cs + '0';

                printf("%s", ans+1);
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}