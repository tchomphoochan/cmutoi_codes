#include <bits/stdc++.h>

typedef long long ll;

const int N = 500010;

int n, gem;
int arr[N];

bool check(ll bad)
{
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (arr[i]+bad-1)/bad;
    }
    return sum <= gem;
}

int main()
{
    scanf("%d%d", &n, &gem);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    ll begin = 1;
    ll end = 1e18;
    while (begin < end) {
        ll mid = (begin+end)/2;
        if (check(mid))
            end = mid;
        else
            begin = mid+1;
    }
    printf("%lld", end);

    return 0;
}