#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MN = 1;
const int MX = 2000;

int main()
{
    for (ll a = 1; a <= MX; ++a) {
        for (ll b = a; b <= MX-a; ++b) {
            for (ll c = b; c <= MX-a-b; ++c) {
                ll s = a+b+c;
                ll p = a*b*c;
                if (p == 1000000) continue;
                ll d = 1000000*s / (p - 1000000);
                p *= d;
                s += d;
                if (d >= c && s*1000000 == p && s <= 2000)
                    printf("%.2f %.2f %.2f %.2f\n", a/100.0, b/100.0, c/100.0, d/100.0);
            }
        }
    }

    return 0;
}