#include <cstdio>
#include <algorithm>

#define N 1000010
#define INF 1e18

typedef long long ll;

int n, k;
int res[N];

ll charge(ll m)
{
    ll p = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        if (p < res[i]) {
            p = m;
            ++c;
        }
        p -= res[i];
    }
    return c;
}

int main()
{
    scanf("%d%d", &n, &k);

    int max = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &res[i]);
        max = std::max(max, res[i]);
    }
    
    ll left = max;
    ll right = INF;
    while (right > left) {
        ll mid = (left + right) / 2;
        if (charge(mid) < k)
            right = mid;
        else
            left = mid+1;
    }
    ll high = right;

    left = max;
    right = INF;
    while (right > left) {
        ll mid = (left + right) / 2;
        if (charge(mid) < k+1)
            right = mid;
        else
            left = mid+1;
    }
    ll low = right;
    
    printf("%lld", high >= INF ? -1 : (high - low));

    return 0;
}