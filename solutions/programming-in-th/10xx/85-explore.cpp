#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 500010;

bool cant[N];
bool dp[N];
vector<int> tp[N];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        tp[x].push_back(y);
    }
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        cant[x] = true;
    }

    dp[0] = true;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (!cant[i-1] && dp[i-1])
            dp[i] = true;
        if (dp[i]) {
            mx = max(mx, i);
            for (auto v : tp[i])
                dp[v] = true;
        }
    }

    if (mx == n)
        printf("1");
    else
        printf("0 %d", mx);

    return 0;
}