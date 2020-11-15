/**
 * toi14_nbk48
 * 
 * aquablitz11 (2019)
 * solution by eliminating redundant items using stack
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int pmax[N];
int sum[N], ix[N];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int s = 0, x, cnt = 0;
    sum[cnt] = -2e9;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        s += x;
        while (s <= sum[cnt])
            --cnt;
        sum[++cnt] = s;
        ix[cnt] = i;
    }

    while (q--) {
        scanf("%d", &x);
        int i = upper_bound(sum+1, sum+cnt+1, x)-sum;
        printf("%d\n", ix[i-1]);
    }
    
    return 0;
}