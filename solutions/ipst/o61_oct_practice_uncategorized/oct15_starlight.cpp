#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int s, n;
int x[N], y[N];

bool check(double p)
{
    bool pass = true;
    double lb = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i]-p > lb) {
            pass = false;
            break;
        }
        lb = x[i]+p;
    }
    if (lb < s)
        pass = false;
    if (pass)
        return true;

    double ub = 0;
    for (int i = 0; i < n; ++i) {
        if (y[i]-p > ub)
            return false;
        ub = y[i]+p;
    }
    if (ub < s)
        return false;

    return true;
}

int main()
{
    scanf("%d%d", &s, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    sort(x, x+n);
    sort(y, y+n);

    double begin = 0;
    double end = s;
    while (end-begin > 0.0001) {
        double mid = (begin+end)/2;
        if (check(mid))
            end = mid;
        else
            begin = mid+0.0001;
    }

    printf("%.3lf", end);

    return 0;
}