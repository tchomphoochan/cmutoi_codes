/**
 * toi10_crazyadmin
 * 
 * aquablitz11 (2018)
 * 100/100
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100010;
const ll INF = 1e18;

int n, k;
ll val[N];

bool check(ll limit)
{
    int cnt = 1;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (val[i] > limit)
            return false;
        if (sum + val[i] > limit) {
            ++cnt;
            sum = 0;
        }
        sum += val[i];
    }
    return cnt <= k;
}

int main()
{
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &val[i]);
    
    ll lo = 1;
    ll hi = INF;
    while (lo < hi) {
        ll mid = (lo+hi)/2;
        if (check(mid))
            hi = mid;
        else
            lo = mid+1;
    }
    printf("%lld\n", lo);
    
    return 0;
}