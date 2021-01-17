#include <cstdio>
#include <algorithm>
#include <deque>

int n, m, k;
int best[101][10001] = {};

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int j = 1; j <= m; ++j)
        scanf("%d", &best[1][j]);
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        std::deque<int> ix;
        for (int j = 1; j <= k; ++j) {
            while (!ix.empty() && best[i-1][j] >= best[i-1][ix.back()])
                ix.pop_back();
            ix.push_back(j);
        }
        for (int j = 1; j <= m; ++j) {
            while (!ix.empty() && ix.front() < j-k)
                ix.pop_front();
            if (j+k <= m) {
                while (!ix.empty() && best[i-1][j+k] >= best[i-1][ix.back()])
                    ix.pop_back();
                ix.push_back(j+k);
            }
            int x;
            scanf("%d", &x);
            best[i][j] = x + best[i-1][ix.front()];
            ans = std::max(ans, best[i][j]);
        }
    }

    printf("%d", ans);
    return 0;
}