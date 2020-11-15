/**
 * toi14_nbk48
 * 
 * aquablitz11 (2019)
 * solution by sorting pairs then binary searching
 */

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int N = 100010;

pii val[N];
int pmax[N];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int sum = 0, c;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c);
        sum += c;
        val[i] = {sum, i};
    }
    sort(val+1, val+n+1);
    for (int i = 1; i <= n; ++i)
        pmax[i] = max(pmax[i-1], val[i].second);
    while (q--) {
        scanf("%d", &c);
        int x = upper_bound(val+1, val+n+1, pii(c, 2e9))-val;
        printf("%d\n", pmax[x-1]);
    }
    
    return 0;
}