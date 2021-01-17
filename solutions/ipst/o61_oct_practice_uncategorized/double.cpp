#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int arr[N];
int qs[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        qs[i] = qs[i-1] + arr[i];
    }
    if (qs[n] % 2 != 0) {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (qs[i] == qs[n]/2) {
            printf("%d\n", i);
            return 0;
        }
    }

    int a, b = 1;
    for (a = 1; a < n; ++a) {
        while (b < n && qs[n]-qs[b] + qs[a] > qs[n]/2)
            ++b;
        if (b >= n) {
            printf("NO\n");
            return 0;
        }
        if (qs[b]-qs[a] == qs[n]/2)
            break;
    }
    if (a != 0) printf("%d ", a);
    printf("%d\n", b);

    return 0;
}