#include <bits/stdc++.h>

using namespace std;

const int N = 22;

double p[N], dp[1<<N];

int main()
{
    // input probability
    int n;
    scanf("%d", &n);
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &p[i]);
        sum += p[i];
    }
    for (int i = 0; i < n; ++i)
        p[i] /= sum;

    for (int i = (1<<n)-2; i >= 0; --i) {
        double num = 1, denom = 1;
        for (int j = 0; j < n; ++j) {
            if (i&(1<<j))
                denom -= p[j];
            else
                num += p[j]*dp[i|(1<<j)];
        }
        dp[i] = num/denom;
    }

    printf("%.9f", dp[0]);
    return 0;
}
