#include <cstdio>
#include <cstring>

char s[100001] = {};

int main()
{
    for (int t = 0; t < 5; ++t) {
        if (t != 0)
            scanf(" ");
        scanf("%s", s);
        int n = strlen(s);

        for (int i = 1; i <= n; ++i) {
            if (n % i != 0)
                continue;

            bool check = true;
            for (int j = 1, l = n / i; j < l; ++j) {
                for (int k = 0; k < i; ++k) {
                    if (s[k] != s[i*j + k]) {
                        check = false;
                        break;
                    }
                }
                if (!check)
                    break;
            }

            if (check) {
                int count = 0;
                for (int j = i; j <= n; j += i) {
                    if (n % j == 0)
                        ++count;
                }
                printf("%d\n", count);
                break;
            }
        }
    }

    return 0;
}