#include <stdio.h>

#define MOD 49999

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[10000];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum = sum + ((2 * i - n + 1) * (arr[i] % MOD)) % MOD;

    int nl = n - 2;
    for (int i = 2; i <= nl; ++i)
        sum = (sum * i) % MOD;

    printf("%d", sum);
    return 0;
}