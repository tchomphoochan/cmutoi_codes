#include <bits/stdc++.h>

using namespace std;

const double INF = 1e10;
const int N = 5;

int n, m;
double arr[N][N];
bool used[N][N];

double bf(int ix)
{
    if (ix == n*m)
        return 0;
    double ans = INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (used[i][j])
                continue;
            used[i][j] = true;
            arr[i-1][j-1] += 0.1*arr[i][j];
            arr[i-1][j] += 0.1*arr[i][j];
            arr[i-1][j+1] += 0.1*arr[i][j];
            arr[i][j-1] += 0.1*arr[i][j];
            arr[i][j+1] += 0.1*arr[i][j];
            arr[i+1][j-1] += 0.1*arr[i][j];
            arr[i+1][j] += 0.1*arr[i][j];
            arr[i+1][j+1] += 0.1*arr[i][j];
            ans = min(ans, arr[i][j]+bf(ix+1));
            arr[i-1][j-1] -= 0.1*arr[i][j];
            arr[i-1][j] -= 0.1*arr[i][j];
            arr[i-1][j+1] -= 0.1*arr[i][j];
            arr[i][j-1] -= 0.1*arr[i][j];
            arr[i][j+1] -= 0.1*arr[i][j];
            arr[i+1][j-1] -= 0.1*arr[i][j];
            arr[i+1][j] -= 0.1*arr[i][j];
            arr[i+1][j+1] -= 0.1*arr[i][j];
            used[i][j] = false;
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%lf", &arr[i][j]);
        }
    }

    double ans = bf(0);
    printf("%.2lf", ans);

    return 0;
}