#include <cstdio>
#include <queue>

#define SPOT 101
#define CAR 2001

using namespace std;

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    int r[SPOT] = {};
    for (int i = 1; i <= n; ++i)
        scanf("%d", &r[i]);
    
    int w[CAR] = {};
    for (int i = 1; i <= m; ++i)
        scanf("%d", &w[i]);

    long long money = 0;
    int spot[SPOT] = {};
    int where[CAR] = {};
    queue<int> q;

    for (int i = 1, l = 2 * m; i <= l; ++i)
    {
        int x;
        scanf("%d", &x);

        if (x > 0)
        {
            bool found = false;
            for (int j = 1; j <= n; ++j)
            {
                if (spot[j] == 0)
                {
                    spot[j] = x;
                    where[x] = j;
                    found = true;
                    break;
                }
            }

            if (!found)
                q.push(x);
        }
        else
        {
            x = -x;
            money += w[x] * r[where[x]];
            spot[where[x]] = 0;

            if (!q.empty())
            {
                int y = q.front();
                where[y] = where[x];
                spot[where[x]] = y;
                q.pop();
            }
        }
    }

    printf("%lld", money);
    return 0;
}