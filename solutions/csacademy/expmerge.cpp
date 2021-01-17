#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

map<pii, double> dp;

double solve(int n, int k)
{
    if (n == 1)
        return 1;
    double &ans = dp[pii(n,k)];
    if (ans != 0)
        return ans;
    int fn = n/2;
    int cn = (n+1)/2;
    ans += k <= fn ? solve(fn, k) : solve(cn, k-fn);
    ans += k <= cn ? solve(cn, k) : solve(fn, k-cn);
    ans /= 2;
    ans += n;
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        if (i != 1)
            printf(" ");
        printf("%.8f", solve(n, i));
    }
    printf("\n");

    return 0;
}
