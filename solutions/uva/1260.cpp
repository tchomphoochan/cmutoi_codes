#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int a[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int s = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            for (int j = i-1; j >= 1; --j) {
                if (a[j] <= a[i])
                    ++s;
            }
        }
        printf("%d\n", s);
    }

    return 0;
}