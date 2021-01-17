#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int N = 100010;
const int MOD = 1e9+7;

pii p[N];
int ft[N];

void put(int i, int x) { for (; i > 0; i -= i&-i) ft[i] = (ft[i]+x)%MOD; }
int get(int i) { int ans = 0; for (; i < N; i += i&-i) ans = (ans+ft[i])%MOD; return ans; }

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &p[i].first, &p[i].second);
    sort(p, p+n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = p[i].second;
        int v = get(x+1);
        ans = (ans+v+1)%MOD;
        put(x, v+1);
    }

    printf("%d\n", ans);
    return 0;
}
