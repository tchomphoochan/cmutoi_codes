#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

int dp[N];

int main()
{
    int n;
    scanf("%d", &n);
    int ansi = 0, ansv = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        dp[x] = dp[x-1]+1;
        if (dp[x] > ansv) {
            ansv = dp[x];
            ansi = x;
        }
    }
    int ansj = ansi-ansv+1;
    printf("%d\n", n-ansv);
    for (int i = ansj-1; i >= 1; --i)
        printf("%d 0\n", i);
    for (int i = ansi+1; i <= n; ++i)
        printf("%d 1\n", i);

    return 0;
}
