#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;
const int INF = 1e9;

int p[10];
int ans[N];

int main()
{
    int n;
    scanf("%d", &n);

    p[0] = INF;
    int mn = 0;
    for (int i = 1; i <= 9; ++i) {
        scanf("%d", &p[i]);
        if (p[i] <= p[mn])
            mn = i;
    }

    int cnt = 0;
    for (int i = 0; n-p[mn]>=0; ++i) {
        ans[i] = mn;
        n -= p[mn];
        cnt = i+1;
    }

    for (int i = 0; i < cnt; ++i) {
        for (int j = 9; j >= mn; --j) {
            if (n+p[mn]-p[j] >= 0) {
                n = n+p[mn]-p[j];
                ans[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < cnt; ++i)
        printf("%d", ans[i]);

    return 0;
}