#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 25;

ll c[N];

int main()
{
    int C;
    scanf("%d", &C);
    while (C--) {

        int n;
        scanf("%d", &n);
        for (int i = 0; i <= n; ++i)
            scanf("%lld", &c[i]);
        
        int d, k;
        scanf("%d%d", &d, &k);

        ll cnt = 0;
        for (int i = 1; ; ++i) {
            cnt += d*i;
            if (cnt >= k) {
                ll ans = 0, mul = 1;
                for (int j = 0; j <= n; ++j) {
                    ans += mul*c[j];
                    mul *= i;
                }
                printf("%lld\n", ans);
                break;
            }
        }

    }

    return 0;
}