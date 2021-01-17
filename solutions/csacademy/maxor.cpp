#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5+10;
const int B = 18;

inline bool hasbit(int conf, int b) { return conf&(1<<b); }
inline int flipbit(int conf, int b) { return conf^(1<<b); }
inline int invertbit(int conf) { return (~conf)&((1<<B)-1); }

int arr[N], dp[1<<B];
ll cnt[1<<B][B];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        ++cnt[arr[i]][B-1];
    }

    // count submask configurations
    for (int conf = (1<<B)-1; conf >= 0; --conf) {
        for (int b = B-1; b >= 0; --b) {
            if (b < B-1)
                cnt[conf][b] += cnt[conf][b+1];
            if (!hasbit(conf, b))
                cnt[conf][b] += cnt[flipbit(conf, b)][b];
        }
        if (cnt[conf][0])
            dp[conf] = conf;
    }

    // find max or
    for (int conf = 0; conf < 1<<B; ++conf) {
        for (int b = 0; b < B; ++b) {
            if (hasbit(conf, b))
                dp[conf] = max(dp[conf], dp[flipbit(conf, b)]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, arr[i]|dp[invertbit(arr[i])]);

    // count pairs
    ll ans2 = 0;
    for (int i = 0; i < n; ++i) {
        if ((arr[i]|ans) == ans)
            ans2 += cnt[ans^arr[i]][0];
        if (arr[i] == ans)
            --ans2;
    }
    ans2 /= 2;
    printf("%d %lld\n", ans, ans2);

    return 0;
}
