#include <bits/stdc++.h>

using namespace std;

const double INF = 1e17;

int main()
{
    int n;
    double s;
    scanf("%d%lf", &n, &s);

    double lastfin = 0;
    for (int i = 0; i < n; ++i) {
        double t, v;
        scanf("%lf%lf", &t, &v);
        double fin = s/v + t;
        if (fin >= lastfin) {
            printf("0\n");
        } else {
            double nv = floor(s/(lastfin-t));
            fin = s/nv + t;
            printf("%.0lf\n", v-nv);
        }
        lastfin = fin;
    }

    return 0;
}