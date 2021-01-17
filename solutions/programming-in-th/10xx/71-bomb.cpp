#include <cstdio>
#include <set>

using namespace std;

struct Charm
{
    int x;
    int y;

    Charm() { }
    Charm(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    // compares by X
    bool operator<(const Charm &o) const
    {
        if (x < o.x)
            return true;
        if (x == o.x)
            return (y < o.y);
        else
            return false;
    }
};

int n, m;
set<Charm> cs;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        cs.insert(Charm(x, y));
    }

    for (int i = 0; i < m; i++)
    {
        int bx, by, br;
        int count = 0;
        scanf("%d %d %d", &bx, &by, &br);

        set<Charm>::iterator lower = cs.lower_bound(Charm(bx - br, -1));
        set<Charm>::iterator upper = cs.upper_bound(Charm(bx + br, 1001));
        for (set<Charm>::iterator curr = lower; curr != upper; )
        {
            if (curr->y >= by - br && curr->y <= by + br)
            {
                count++;
                set<Charm>::iterator temp = curr++;
                cs.erase(temp);
            }
            else
            {
                ++curr;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}