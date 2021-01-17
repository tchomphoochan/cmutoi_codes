#include <cstdio>

using namespace std;

class Rectangle
{
    public:
    int x1, y1, x2, y2;

    bool overlap(const Rectangle &other) const
    {
        return (x1 < other.x2 && y1 > other.y2 && x2 > other.x1 && y2 < other.y1);
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Rectangle original[n];
    for (int i = 0; i < n; i++)
    {
        Rectangle &ori = original[i];
        scanf("%d %d %d %d", &ori.x1, &ori.y1, &ori.x2, &ori.y2);
    }

    for (int i = 0; i < m; i++)
    {
        Rectangle check;
        scanf("%d %d %d %d", &check.x1, &check.y1, &check.x2, &check.y2);
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (check.overlap(original[j]))
                count++;
        }
        printf("%d\n", count);
    }
}