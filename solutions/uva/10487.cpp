#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int a[N];

int main()
{
    int c = 0;
    while (true) {
        ++c;
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int m;
        scanf("%d", &m);
        printf("Case %d:\n", c);
        while (m--) {
            int x;
            scanf("%d", &x);
            int cls = -1e9;
            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    int s = a[i]+a[j];
                    if (abs(s-x) < abs(cls-x))
                        cls = s;
                }
            }
            printf("Closest sum to %d is %d.\n", x, cls);
        }
    }

    return 0;
}