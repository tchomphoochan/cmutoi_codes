#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9

typedef pair<int, int> ii;

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);

    vector<ii> rn;
    rn.reserve(n*2);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y)
            std::swap(x, y);
        rn.push_back({x, 1});
        rn.push_back({y, -1});
    }

    sort(rn.begin(), rn.end(), [&] (const ii a, const ii b) {
        return (a.first < b.first
        || (a.first == b.first && a.second > b.second));
    });

    int c = 0;
    int s = INF, e = INF;
    for (auto r : rn) {
        c += r.second;
        if (c == n)
            s = r.first;
        else if (c == n-1 && s != INF) {
            e = r.first;
            break;
        }
    }

    if (e == INF) {
        printf("-1");
    } else if (s <= p && p <= e) {
        printf("0");
    } else if (p < s) {
        printf("%d", s-p);
    } else {
        printf("%d", p-e);
    }

    return 0;
}