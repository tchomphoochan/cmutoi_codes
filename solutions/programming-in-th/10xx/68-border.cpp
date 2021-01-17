#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 110;

int left[N][N], right[N][N], up[N][N], down[N][N];
int num[N*N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &up[i][j]);
            if (i != 0)
                down[i-1][j] = up[i][j];
        }
        if (i != n) {
            for (int j = 0; j <= n; ++j) {
                scanf("%d", &left[i][j]);
                if (j != 0)
                    right[i][j-1] = left[i][j];
            }
        }
    }

    int c = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            num[c++] = 3*up[i][j]-3*down[i][j]+5*left[i][j]-5*right[i][j];
        }
    }

    sort(num, num+c);
    ll ans = 0;
    for (int i = 0; i < k; ++i)
        ans += num[i];
    
    printf("%lld", ans);

    return 0;
}