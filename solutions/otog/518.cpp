#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
const int N = 110;

int n;
int pre[N], in[N];
ll dp[N][N];

bool match(int prei, int prej, int ini, int inj)
{
    int sz = prej-prei+1;
    bool has1[N] = {}, has2[N] = {};
    for (int i = 0; i < sz; ++i) {
        has1[pre[prei+i]] = true;
        has2[in[ini+i]] = true;
    }
    
    for (int i = 0; i < n; ++i) {
        if (has1[i] != has2[i])
            return false;
    }

    return true;
}

ll solve(int prei, int prej, int ini, int inj)
{
    if (prei >= prej)
        return 1;
    if (dp[prei][prej])
        return dp[prei][prej];

    int sz = prej-prei+1, mid = sz;
    for (int i = 0; i < sz; ++i) {
        if (pre[prei] == in[ini+i]) {
            mid = i;
            break;
        }
    }
    if (mid == sz) {
        printf("NOPE\n");
        pre[12321521652] = 12341242141; // LEL ERROR
    }

    ll ans = 0;
    ll lp = solve(prei+1, prei+mid, ini, ini+mid-1);
    for (int i = mid; i < sz; ++i) {
        if (match(prei+mid+1, prei+i, ini+mid+1, ini+i)) {

            ll mp = solve(prei+mid+1, prei+i, ini+mid+1, ini+i);
            ll rp = solve(prei+i+1, prej, ini+i+1, inj);
            ans += ((lp*mp%MOD)*rp)%MOD;
            ans %= MOD;

        }
    }

    return dp[prei][prej] = ans%MOD;

}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &in[i]);
    
    ll ans = solve(0, n-1, 0, n-1);
    printf("%lld", ans);

    return 0;
}