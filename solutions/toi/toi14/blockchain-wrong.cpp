/**
 * toi14_blockchain
 * 
 * aquablitz11 (2019)
 * This solution gets 95/100 because using 0-based indexing instead of
 * 1-based indexing results in collisions of 0-valued hashes.
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1030;
const ll PB = 98765431;

ll PP[N];

int main()
{
    PP[0] = 1;
    for (int i = 1; i < N; ++i)
        PP[i] = PP[i-1]*PB;
    int t, q;
    scanf("%d%d", &t, &q);
    map<ll, ll> cnt;
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        ll hsh = 0;
        for (int j = 0; j < n-1; ++j) {
            int u, v;
            scanf("%d%d", &u, &v);
            //++u, ++v;
            hsh += u*PP[u]*v*PP[v];
        }
        ++cnt[hsh];
    }
    for (int i = 0; i < q; ++i) {
        int n;
        scanf("%d", &n);
        ll hsh = 0;
        for (int j = 0; j < n-1; ++j) {
            int u, v;
            scanf("%d%d", &u, &v);
            //++u, ++v;
            hsh += u*PP[u]*v*PP[v];
        }
        printf("%lld\n", cnt[hsh]);
    }
    
    return 0;
}