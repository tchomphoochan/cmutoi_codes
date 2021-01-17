/**
 * toi15_medal
 * 
 * aquablitz11 (2020)
 * 100/100
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+10;
int A[N], B[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &A[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &B[i]);
    sort(A, A+n);
    sort(B, B+n, greater<int>());
    ll mn = 1e18, mx = 0;
    for (int i = 0; i < n; ++i) {
        mn = min(mn, (ll)A[i]+B[i]);
        mx = max(mx, (ll)A[i]+B[i]);
    }
    printf("%lld\n", mx-mn);
    
    return 0;
}