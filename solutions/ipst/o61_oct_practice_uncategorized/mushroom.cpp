#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int main()
{
    int n;
    double l, h;
    scanf("%d%lf%lf", &n, &l, &h);

    multiset<double> pos;
    while (n--) {
        int c;
        scanf("%d", &c);
        while (c--) {
            double p;
            scanf("%lf", &p);
            pos.insert(p);
        }

        double x, y;
        scanf("%lf%lf", &x, &y);
        double lim = l+h*x/y;
        auto ptr = pos.lower_bound(lim);
        pos.erase(ptr, pos.end());
        printf("%d\n", pos.size());
    }

    return 0;
}