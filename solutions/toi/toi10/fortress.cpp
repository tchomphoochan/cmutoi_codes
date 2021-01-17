/**
 * toi10_fortress
 * 
 * aquablitz11 (2017)
 * 100/100
 */

#include <cstdio>

typedef long long ll;

int main()
{
    for (int t = 0; t < 20; ++t) {
        ll m, n;
        scanf("%lld%lld", &m, &n);
        ll ans;
        if (m % 2 != 0 || m < 2*n || m > 4*n) { 
            ans = 0;
        } else {
            ll i = (m/2)-n;
            ans = n-i+1;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
