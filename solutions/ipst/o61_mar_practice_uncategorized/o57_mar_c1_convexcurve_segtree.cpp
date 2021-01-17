#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdi = pair<double, int>;

#define pb push_back
#define F first
#define S second

const int INF = 1e9;
const int N = 5010;

class segtree {
    private:
    int n;
    vector<double> coord;
    vector<int> val;
    int pos(double x) { return lower_bound(coord.begin(), coord.end(), x)-coord.begin(); }
    public:
    segtree() { }
    segtree(vector<pdi> ini) {
        for (auto p : ini)
            coord.pb(p.F);
        sort(coord.begin(), coord.end());
        coord.resize(unique(coord.begin(), coord.end()) - coord.begin());
        n = coord.size();
        val = vector<int>(2*n);
        for (auto p : ini)
            val[n+pos(p.F)] = max(val[n+pos(p.F)], p.S);
        for (int i = n-1; i > 0; --i)
            val[i] = max(val[i<<1], val[i<<1|1]);
    }
    int query(double x) {
        int l = pos(x);
        int r = n-1;
        int ans = 0;
        for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans = max(ans, val[l++]);
            if (r&1) ans = max(ans, val[--r]);
        }
        return ans;
    }
};

int n, h[N];
segtree t[N];

double slope(int i, int j) {
    return (h[i]-h[j])*1.0/(i-j);
}

int main()
{
    scanf("%d", &n);

    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
        vector<pdi> val;
        val.pb(pdi(INF, 1));
        for (int j = 1; j < i; ++j) {
            int v = t[j].query(slope(i, j))+1;
            ans = max(ans, v);
            val.pb({slope(i, j), v});
        }
        t[i] = segtree(val);
    }
    printf("%d\n", ans);

    return 0;
}