#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 110;
int x[N], y[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    double mx = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k)
                mx = max(mx, (x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-y[i]*x[j]-y[j]*x[k]-y[k]*x[i])/2.0);
        }
    }
    printf("%.3f\n", mx);

    return 0;
}