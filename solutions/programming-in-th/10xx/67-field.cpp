#include <cstdio>
#include <set>

using namespace std;

struct Point
{
    int r, c;
    Point() { }
    Point(int r, int c)
    {
        this->r = r;
        this->c = c;
    }

    bool operator<(const Point &other) const
    {
        if (r < other.r)
            return true;
        else if (r == other.r)
            return c < other.c;
        else
            return false;
    }
};

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    // problems prefer 1-indexed shits
    int field[101][101];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            scanf("%d", &field[i][j]);
    }
    // 1, 2, 3, 4 - N, E, S, W

    for (int i = 0; i < k; i++)
    {
        Point cur;
        int &r = cur.r;
        int &c = cur.c;
        scanf("%d %d", &c, &r);

        set<Point> stepped;
        stepped.insert(cur);

        while (true)
        {
            switch (field[r][c])
            {
                case 1: r--; break;
                case 2: c++; break;
                case 3: r++; break;
                case 4: c--; break;
            }

            if (stepped.count(cur) != 0)
            {
                printf("NO\n");
                break;
            }
            if (r <= 0)
            {
                printf("N\n");
                break;
            }
            if (r > m)
            {
                printf("S\n");
                break;
            }
            if (c <= 0)
            {
                printf("W\n");
                break;
            }
            if (c > n)
            {
                printf("E\n");
                break;
            }
            stepped.insert(cur);
        }
    }
}