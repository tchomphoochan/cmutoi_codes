#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int N = 25;

int c[N];
map<int, int> dp[N];

ll solve(int n, int k)
{
    if (n == 1) return k;
    if (dp[n][k] != 0) return dp[n][k];
    int v1 = (2*k+1-c[n-1])/2;
    int v2 = (2*k+1-c[n-1]+1)/2;
    if (v1 <= 0 || v2 <= 0) {
        printf("-1");
        exit(0);
    }
    return solve(n-1, v1) + solve(n-1, v2);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n-1; ++i)
        scanf("%d", &c[i]);

    printf("%lld\n", solve(n, k));

    return 0;
}