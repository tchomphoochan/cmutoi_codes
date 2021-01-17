#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n, pe, po, x, t=0;
    scanf("%d", &n);
    pe = po = n;
    for (int i = 0; i < n*2; ++i) {
        scanf("%d", &x);
        if (x%2 == 0) {
            t = max(t, 0);
            po -= (++t >= 3 ? 3 : 1);
        } else {
            t = min(t, 0);
            pe -= (--t <= -3 ? 3 : 1);
        }
        if (po <= 0) {
            printf("%d\n%d\n", 0, x);
            break;
        }
        if (pe <= 0) {
            printf("%d\n%d\n", 1, x);
            break;
        }
    }

    return 0;
}