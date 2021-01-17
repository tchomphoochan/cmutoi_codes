#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main()
{
    int k;
    while (scanf("%d", &k) != EOF) {
        vector<pll> ans;
        for (ll x = k+1; x <= k*2; ++x) {
            ll y = (x*k)/(x-k);
            if (x*y != k*(x+y))
                continue;
            ans.push_back({y, x});
        }
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            printf("1/%d = 1/%lld + 1/%lld\n", k, ans[i].first, ans[i].second);
        }
    }

    return 0;
}