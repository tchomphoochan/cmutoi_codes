#include <bits/stdc++.h> // <- include everything
using namespace std;

// THIS PROBLEM HAS LIMITS RIGHT AT 2^31. INT IS NOT ENOUGH.

using ll = long long;
const int N = 2e6+10;

ll n, sz[N];

bool check(ll lim)
{
    vector<ll> seq;
    for (ll i = 0; i < n; ++i) {
        if (sz[i] > lim)
            seq.push_back(sz[i]);
    }
    for (ll i = 0; i < seq.size(); i += 2) {
        if (seq[i] != seq[i+1])
            return false;
    }
    return true;
}

int main()
{
    scanf("%lld", &n);
    for (ll i = 0; i < n; ++i)
        scanf("%lld", &sz[i]);

    ll b = 0;
    ll e = (1ll<<31);
    while (b < e) {
        ll m = (b+e)/2;
        if (check(m))
            e = m;
        else
            b = m+1;
    }
    printf("%lld\n", b);
    
    return 0;
}