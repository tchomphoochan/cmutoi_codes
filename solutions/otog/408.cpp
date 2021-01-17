#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int N = 25;

int main()
{
    ll fact[N] = {};
    fact[1] = 1;
    for (int i = 2; i <= 20; ++i)
        fact[i] = fact[i-1]*i;

    for (int T = 0; T < 1000; ++T) {

        int num[N] = {}, oldv[N] = {}, val[N] = {};

        ll n, a;
        scanf("%llu%llu", &n, &a);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &num[i]);
            printf("%d ", num[i]);
            oldv[i+1] = num[i];
        }
        sort(oldv+1, oldv+1+n);
        for (int i = 0; i < n; ++i) {
            auto ix = lower_bound(oldv+1, oldv+1+n, num[i]) - oldv;
            num[i] = ix;
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = -1;
            for (int j = 1; j <= num[i]; ++j) {
                if (!val[j])
                    ++v;
            }
            val[num[i]] = true;
            ans += fact[n-1-i] * v;
        }
        printf("is permutation no. %llu\n", ans);
        ll old = ans;
        ans = (ans+a) % fact[n];

        for (int i = 0; i <= n; ++i)
            val[i] = false;
        for (int i = 0; i < n; ++i) {
            ll f = fact[n-1-i];
            for (int j = n-1-i; j >= 0; --j) {
                if (f*j <= ans) {
                    ans -= f*j;
                    int cnt = -1, k;
                    for (k = 1; k <= n; ++k) {
                        if (!val[k])
                            ++cnt;
                        if (cnt == j)
                            break;
                    }
                    val[k] = true;
                    printf("%d ", oldv[k]);
                    break;
                }
            }
        }
        printf("is permutation no. %llu + %llu\n", old, a);

    }

    return 0;
}