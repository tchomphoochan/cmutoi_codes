#include <cstdio>
#include <algorithm>

int n;
int wall[1000002] = {};
int is[1000002] = {};
int ds[1000002] = {};

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &wall[i]);
        is[i] = std::max(is[i-1], wall[i]);
    }
    for (int i = n; i >= 1; --i)
        ds[i] = std::max(ds[i+1], wall[i]);
    for (int i = 1; i < n; ++i)
        printf("%d ", std::min(is[i], ds[i+1]));
    return 0;
}