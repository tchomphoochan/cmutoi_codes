/**
 * Code Jam 2020 Round 2
 * A. Incremental House of Pancakes
 * 
 * aquablitz11 (2020-05-16)
 * After removing the initial excess, notice that the stack will alternate in being taken off.
 * So, it is only the matter of binary searching for when one stack gets below zero and using arithmetic.
 * I didn't deal with the symmetry in this problem well, hence the ugly code.
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;
const ll MX = 2e9; // check this

ll trinum(ll l, ll r) {
    if ((l+r)%2 == 0)
        return (l+r)/2*(r-l+1);
    else
        return (r-l+1)/2*(l+r);
}
ll septrinum(ll l, ll r) {
    if ((l+r)%2 == 0)
        return (l+r)/2*((r-l)/2+1);
    else
        return (l+r)*((r-l)/2+1)/2;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        ll l, r, k;
        scanf("%lld%lld", &l, &r);

        // find first drops
        if (l >= r) {
            ll b = 1, e = MX;
            while (b < e) {
                ll m = (b+e)/2;
                if (l-trinum(1,m) < r)
                    e = m;
                else
                    b = m+1;
            }
            k = b;
            // CHECK FAIL CASE
            if (l-trinum(1, k) < 0) {
                l -= trinum(1, k-1);
                printf("Case #%d: %lld %lld %lld\n", t, k-1, l, r);
                continue;
            }
            l -= trinum(1, k-1);
            --k;
        } else {
            ll b = 1, e = MX;
            while (b < e) {
                ll m = (b+e)/2;
                if (r-trinum(1,m) < l)
                    e = m;
                else
                    b = m+1;
            }
            k = b;
            // CHECK FAIL CASE
            if (r-trinum(1, k) < 0) {
                r -= trinum(1, k-1);
                printf("Case #%d: %lld %lld %lld\n", t, k-1, l, r);
                continue;
            }
            r -= trinum(1, k-1);
            --k;
        }

        //printf("l=%lld, r=%lld, k=%lld\n", l, r, k);
        ll b, e, k1, k2, ansl, ansr, ansn;
        if (l < r) {

            // for right
            b = 0, e = MX; // check
            while (b < e) {
                ll m = (b+e)/2;
                ll v1 = k+1;
                ll v2 = k+1 + m*2;
                if (r-septrinum(v1, v2) < 0)
                    e = m;
                else
                    b = m+1;
            }
            ll k2 = k+1 + b*2;
            // for left
            b = 0, e = MX; // check
            while (b < e) {
                ll m = (b+e)/2;
                ll v1 = k+2;
                ll v2 = k+2 + m*2;
                if (l-septrinum(v1, v2) < 0)
                    e = m;
                else
                    b = m+1;
            }
            ll k1 = k+2 + b*2;
            //printf("l < r: found k1=%lld, k2=%lld", k1, k2);

            if (k1 < k2) {
                ansn = k2-2;
                ansl = l-septrinum(k+2, k1-2);
                ansr = r-septrinum(k+1, k2-2);
            } else {
                ansn = k1-2;
                ansl = l-septrinum(k+2, k1-2); // dont forget this
                ansr = r-septrinum(k+1, k2-2);
            }

        } else { // l >= r

            // for right
            b = 0, e = MX; // check
            while (b < e) {
                ll m = (b+e)/2;
                ll v1 = k+2;
                ll v2 = k+2 + m*2;
                if (r-septrinum(v1, v2) < 0)
                    e = m;
                else
                    b = m+1;
            }
            ll k2 = k+2 + b*2;
            // for left
            b = 0, e = MX; // check
            while (b < e) {
                ll m = (b+e)/2;
                ll v1 = k+1;
                ll v2 = k+1 + m*2;
                if (l-septrinum(v1, v2) < 0)
                    e = m;
                else
                    b = m+1;
            }
            ll k1 = k+1 + b*2;
            //printf("found k1=%lld, k2=%lld", k1, k2);

            if (k1 < k2) {
                ansn = k2-2;
                ansl = l-septrinum(k+1, k1-2);
                ansr = r-septrinum(k+2, k2-2);
            } else {
                ansn = k1-2;
                ansl = l-septrinum(k+1, k1-2);
                ansr = r-septrinum(k+2, k2-2);
            }

        }

        printf("Case #%d: %lld %lld %lld\n", t, ansn, ansl, ansr);
    
    }
    
    return 0;
}