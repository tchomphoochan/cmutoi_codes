#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define N 2000002

typedef std::pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    std::vector<ii> li;
    li.reserve(n*2);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        li.push_back({x, 1});
        li.push_back({y, -1});
    }
    sort(li.begin(), li.end(), [&] (ii a, ii b) {
        if (a.first < b.first)
            return true;
        else if (a.first > b.first)
            return false;
        else
            return a.second < b.second;
    });

    n *= 2;
    int count = 0, max = 0;
    for (int i = 0; i < n; ++i) {
        max = std::max(max, count += li[i].second);
    }
    printf("%d", max);

    return 0;
}