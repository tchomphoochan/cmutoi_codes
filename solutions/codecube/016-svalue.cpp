#include <cstdio>
#include <algorithm>

int n;
int arr[2000];
int main()
{
    scanf("%d", &n);
    int n2 = (n << 1);
    for (int i = 0; i < n2; ++i)
        scanf("%d", &arr[i]);
    std::sort(arr, arr + n2);
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += (long long) arr[i] * arr[n2 - i - 1];
    printf("%lld", sum);

    return 0;
}