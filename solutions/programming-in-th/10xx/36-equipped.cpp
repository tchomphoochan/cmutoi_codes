#include <bits/stdc++.h>
using namespace std;

const int inf = 2e+9;

int p[1 << 10];

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int all = 1 << k;

    fill(p, p+(1<<8), inf);
    p[0] = 0;
    
    for (int i = 0; i < n; ++i) {
        int w;
        scanf("%d",&w);
        int now_state = 0;
        for (int j = 0; j < k; ++j) {
            int bit;
            scanf("%d", &bit);

            now_state |= bit;
            now_state <<= 1;
        }
        now_state >>= 1;
        for (int j = 0; j <= all-1; ++j) p[j | now_state] = min(p[j] + w , p[j|now_state]);
        
    }
    printf("%d\n",p[all-1]);
    return 0;
}