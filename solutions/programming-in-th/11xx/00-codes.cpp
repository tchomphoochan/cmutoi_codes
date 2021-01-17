#include <cstdio>

using namespace std;

typedef long long ll;

ll choose2(ll n)
{
    return ((n * n) - n) / 2;
}

int main()
{
    int n;
    scanf("%d", &n);

    int hunds[10] = {};
    int tens[10] = {};
    int unit[10] = {};
    int ht[100] = {};
    int hu[100] = {};
    int tu[100] = {};
    int htu[1000] = {};
    for (int i = 0; i < n; i++)
    {
        char h, t, u;
        scanf(" %c%c%c", &h, &t, &u);
        h -= '0';
        t -= '0';
        u -= '0';

        hunds[h]++;
        tens[t]++;
        unit[u]++;

        ht[h * 10 + t]++;
        hu[h * 10 + u]++;
        tu[t * 10 + u]++;

        htu[h * 100 + t * 10 + u]++;
    }

    ll total = 0;
    for (int i = 0; i < 10; i++)
        total += choose2(unit[i]) + choose2(tens[i]) + choose2(hunds[i]);
    for (int i = 0; i < 100; i++)
        total -= choose2(ht[i]) + choose2(hu[i]) + choose2(tu[i]);
    for (int i = 0; i < 1000; i++)
        total += choose2(htu[i]);
    
    printf("%lld", total);
    return 0;
}