#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

const int N = 63000;

int num[2][2][N];
int cnt[2][2];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &num[i%2][j%2][cnt[i%2][j%2]++]);
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            sort(num[i][j], num[i][j]+cnt[i][j]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < cnt[0][0]; ++i) {
        ans += (ll)num[0][0][i]*num[0][1][i]*num[1][0][i]*num[1][1][i];
    }

    printf("%llu", ans);
    return 0;
}