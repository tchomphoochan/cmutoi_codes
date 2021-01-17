/**
 * toi11_cannon
 * 
 * aquablitz11 (2020)
 */

#include <bits/stdc++.h>
using namespace std;

const int L = (int)1e7+10;
int qs[L];

int main()
{
    int n, m, k, l;
    scanf("%d%d%d%d", &n, &m, &k, &l);
    while (n--) {
        int x; scanf("%d", &x);
        ++qs[x+1];
    }
    for (int i = 1; i < L; ++i)
        qs[i] += qs[i-1];
    
    while (k--) {
        int last = 0, ans = 0;
        for (int i = 0; i < m; ++i) {
            int x; scanf("%d", &x); ++x;
            int left = max(last+1, x-l);
            int right = min(x+l, L-1);
            ans += qs[right]-qs[left-1];
            last = right;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}