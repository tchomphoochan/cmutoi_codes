#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll MOD = 1e9+7;

vector<vi> multi(vector<vi> a, vector<vi> b)
{
    vector<vi> r(a.size(), vi(b[0].size()));
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            for (int k = 0; k < a[0].size(); ++k)
                r[i][j] = (r[i][j] + a[i][k]*b[k][j])%MOD;
        }
    }
    return r;
}

int main()
{
    ll k;
    scanf("%lld", &k);
    --k;

    vector<vi> v = {{1}, {0}, {0}, {0}, {1}};
    vector<vi> m = {
        {1, 1, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 1, 3, 3}
    };
    while (k > 0) {
        if (k&1)
            v = multi(m, v);
        k >>= 1;
        m = multi(m, m);
    }
    printf("%lld\n", (v[3][0]+v[4][0])%MOD);

    return 0;
}
