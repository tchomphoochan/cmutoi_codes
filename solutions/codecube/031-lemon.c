#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    long long count[10001] = {1, 1};
    for (int i = 2; i <= n; ++i) {
        for (int left = i-1; left >= 0; --left) {
            int right = i-left-1;
            count[i] += count[left] * count[right];
            count[i] %= 909091;
        }
    }
    printf("%lld", count[n]);
    return 0;
}