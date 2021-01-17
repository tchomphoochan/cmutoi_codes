#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int main()
{
    int n;
    scanf("%d", &n);
    int tails[100001] = {};

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        tails[x]++;
    }

    int a;
    scanf("%d", &a);

    if (a > 200000)
    {
        printf("%d", 0);
        return 0;
    }

    ull count = 0;
    for (int i = (a > 100000 ? a - 100000 : 0), end = ceil(a / 2.0) - 1; i <= end; i++)
        count += (ull) tails[i] * tails[a - i];
    if (a % 2 == 0)
        count += ((ull) tails[a / 2] * tails[a / 2] - tails[a / 2]) / 2;
    
    printf("%llu", count);
    return 0;
}