#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1010;
const int MOD = 60001;

bool dp[N][MOD+10];

inline int mod(int x)
{
    x %= MOD;
    return x < 0 ? x+MOD : x;
}

int main()
{
    int n;
    scanf("%d", &n);

    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        int val;
        scanf("%d", &val);
        val = mod(val);
        for (int j = 0; j < MOD; ++j) {
            int nv = j-val;
            nv = mod(nv);
            if (dp[i-1][j] || dp[i-1][nv])
                dp[i][j] = true;
        }
    }

    int mx = 0;
    for (int i = 0; i < MOD; ++i) {
        int val = i <= (MOD-1)/2 ? i : i-MOD;
        if (dp[n][val])
            mx = max(mx, val);
    }

    printf("%d", mx);
    return 0;
}