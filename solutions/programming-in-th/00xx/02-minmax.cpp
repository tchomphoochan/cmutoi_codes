#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int min = 2e9+1, max = -(2e9+1);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x < min)
            min = x;
        if (x > max)
            max = x;
    }
    printf("%d\n%d\n", min, max);

    return 0;
}