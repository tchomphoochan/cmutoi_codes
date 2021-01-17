#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        map<int, int> factors;
        for (int i = 2; i <= sqrt(x); i++)
        {
            while (x % i == 0)
            {
                if (factors.count(i) > 0)
                    factors[i] += 1;
                else
                    factors[i] = 1;
                x /= i;
            }
        }

        int g = 1;
        if (!factors.empty())
            g = (x > 1 ? 1 : factors.begin()->second);
        for (map<int, int>::iterator it = factors.begin(); it != factors.end(); ++it)
        {
            if (it == factors.begin())
                continue;
            g = gcd(g, it->second);
        }

        if (g == 1)
            printf("NO\n");
        else
            printf("%d\n", g);
    }

    return 0;
}