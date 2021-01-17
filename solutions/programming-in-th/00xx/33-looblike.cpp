#include <stdio.h>

int arr[10001];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        arr[x] += 1;
    }
    int mxcnt = 0;
    for (int i = 1; i <= 10000; ++i) {
        if (arr[i] > mxcnt)
            mxcnt = arr[i];
    }
    for (int i = 1; i <= 10000; ++i) {
        if (arr[i] == mxcnt)
            printf("%d ", i);
    }
    return 0;
}