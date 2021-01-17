#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

double a[N], b[N], p[N][N], dp[N][N];

int main()
{
    int t, n;
    scanf("%d%d", &t, &n);
    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf", &p[i][j]);
            p[i][j] /= 100.0;
        }
    }

    a[n] = 1;
    b[n] = 0;
    for (int i = 1; i <= t; ++i) {
        for (int j = n-1; j >= 0; --j) {
            a[j] = p[i][j]*a[j+1];
            b[j] = p[i][j]*b[j+1] + 1 + (1-p[i][j])*dp[i-1][(j+1)%n];
        }
        double x = b[0]/(1-a[0]);
        for (int j = 0; j < n; ++j)
            dp[i][j] = a[j]*x + b[j];
    }

    printf("%.8f\n", dp[t][0]);
    return 0;
}
