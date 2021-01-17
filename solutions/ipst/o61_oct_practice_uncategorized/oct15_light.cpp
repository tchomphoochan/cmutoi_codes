#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef pair<int, int> ii;

const int MOD = 2007;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<ii> v;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        v.pb({x, 1});
        v.pb({y, -1});
    }
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        v.pb({x, 0});
    }
    sort(v.begin(), v.end());

    int cnt = 0, ans = 0;
    for (auto d : v) {
        int x, a;
        tie(x, a) = d;
        cnt += a;
        cnt %= MOD;
        if (a == 0) {
            ans += cnt;
            ans %= MOD;
        }
    }

    printf("%d", ans);

    return 0;
}