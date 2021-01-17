#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct Dot
{
    int x, y;
    bool operator<(const Dot &other) const
    {
        return y < other.y;
    }
};


int t, n, h;
Dot dots[100000];

int main(void)
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &h);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &dots[i].x, &dots[i].y);
        sort(dots, dots + n);

        int ans = 2e9;
        for (int i = 0; i < n; ++i)
        {
            for (int j = n - 1; j > i; --j)
            {
                if (dots[j].y - dots[i].y < h)
                    break;
                int f = abs(dots[i].x - dots[j].x);
                if (f < ans)
                    ans = f;
            }
        }

        printf("%d\n", (ans >= 2e9 ? -1 : ans));
    }
    return 0;
}