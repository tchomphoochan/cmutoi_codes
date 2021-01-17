/**
 * toi11_labor
 * 
 * aquablitz11 (2017)
 */

#include <cstdio>

typedef long long ll;

#define INF 1e18
#define N 1000010

int n;
ll m;
int spd[N];

bool check(ll t)
{
    ll c = m;
    for (int i = 0; i < n; ++i) {
        c -= t/spd[i];
        if (c <= 0)
            return true;    
    }

    return false;
}

int main()
{
    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &spd[i]);
    
    ll left = 1;
    ll right = INF;
    while (left < right) {
        ll mid = (left+right)/2;
        if (check(mid))
            right = mid;
        else
            left = mid+1;
    }

    printf("%lld\n", right);
    return 0;
}