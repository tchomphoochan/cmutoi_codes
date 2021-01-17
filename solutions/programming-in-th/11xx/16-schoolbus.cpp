#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const ll MUL = 1e8;
const int N = 1e6+10;

int n;
ll coord[N];

bool check(ll allowed)
{
    ll bus = 0;
    int j = 0;
    int i = 0;
    while (i < n) {
        ll mn = INF, mx = 0;
        while (i < n) {
            ll nmn = min(mn, coord[i]);
            ll nmx = max(mx, coord[i]);
            ll dist = bus > (nmx+nmn)/2 ? max(bus-nmn, nmx-bus) : (nmx-nmn)/2;
            ++i;
            if (dist > allowed) {
                --i;
                break;
            }
            mn = nmn;
            mx = nmx;
        }
        if (i == j)
            return false;    
        bus = max(bus, (mn+mx)/2);
        j = i;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    ll left = INF;
    ll right = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &coord[i]);
        coord[i] *= MUL;
        left = min(left, coord[i]);
        right = max(right, coord[i]);
    }

    right = right-left;
    left = 0;
    while (left < right) {
        ll mid = (left+right)/2;
        if (check(mid))
            right = mid;
        else
            left = mid+1;
    }

    printf("%.6lf", 1.0*right/MUL);
    return 0;
}