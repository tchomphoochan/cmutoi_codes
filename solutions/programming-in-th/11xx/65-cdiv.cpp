#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

int main()
{
    int n;
    scanf("%d" ,&n);

    map<ll, int> numbers[10];
    for (int i = 0; i < n; i++)
    {
        ll number;
        scanf("%lld", &number);

        for (ll fac = 2; fac <= ceil(sqrt(number)); ++fac)
        {
            while (number % fac == 0)
            {
                //map<ll, int>::iterator found = numbers[i].find(fac);
                //if (found == numbers[i].end())
                //    numbers[i][fac] = 1;
                //else
                    numbers[i][fac] += 1;
                number /= fac;
            }
        }
        if (number != 1)
            numbers[i][number] += 1;
    }

    ll ans = 1;
    for (map<ll, int>::iterator it = numbers[0].begin(); it != numbers[0].end(); ++it)
    {
        const ll &fac = it->first;
        const int &count = it->second;
        ll best = (1 << 31);
        for (int i = 0; i < n; i++)
        {
            map<ll, int>::iterator found = numbers[i].find(fac);
            if (found != numbers[i].end())
                best = min(best, (ll)found->second);
            else
            {
                best = 0;
                break;
            }
        }
        ans *= (best + 1);
    }
    printf("%lld", ans);

    return 0;
}