#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    while (b != 0) {
        ll r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld", a*b/gcd(a,b));

    return 0;
}