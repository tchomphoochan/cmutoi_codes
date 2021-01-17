#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef long long ll;

int n, w, k;
ll H[100001] = {};
ll sum[100001] = {};

bool check(int h)
{
    memset(sum + 1, 0, sizeof(ll) * n);
    ll count = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum[i] += sum[i - 1];
        if (H[i] - sum[i] > h)
        {
            ll required = H[i] - sum[i] - h;
            sum[i] += required;
            count += required;
            if (i + w <= n)
                sum[i + w] -= required;
        }
    }
    return count <= k;
}

int main(void)
{
    ll max = 0;
    scanf("%d%d%d", &n, &w, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &H[i]);
        if (H[i] > max)
            max = H[i];
    }
    
    int left = 0;
    int right = max;
    while (right > left)
    {
        int mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }

    printf("%d", left);

    return 0;
}