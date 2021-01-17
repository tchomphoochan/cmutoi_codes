#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1010;

int X[N][N];
int Y[N][N];
int cnt[N];
int c[N];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            scanf("%d", &X[i][j]);
        }
        for (int j = 0; j < k; ++j) {
            scanf("%d", &Y[i][j]);
            if (X[i][j] > Y[i][j])
                swap(X[i][j], Y[i][j]);
        }
    }

    int mx = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            scanf("%d", &c[j]);
        }
        for (int j = 0; j < n; ++j) {
            bool pass = true;
            for (int p = 0; p < k && pass; ++p) {
                if (c[p] > Y[j][p] || c[p] < X[j][p])
                    pass = false;
            }
            if (pass) {
                mx = max(mx, ++cnt[j]);
            }
        }
    }
    
    int h = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == mx)
            ++h;
    }

    printf("%d\n", h);
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == mx) {
            printf("%d", i+1);
            if (--h)
                printf(" ");
        }
    }

    return 0;
}