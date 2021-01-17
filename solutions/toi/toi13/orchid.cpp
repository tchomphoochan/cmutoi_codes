#include <stdio.h>
using namespace std;

const int N = 1000005;

int a[N], L[N];

int bsearch(int S, int E, int key) {
    while (S < E) {
        int mid = (S+E)/2;
        if (key < L[mid])
            E = mid;
        else
            S = mid+1;
    }
    return E;
}

int main () {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    int len = 1;
    L[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        if (a[i] < L[1]) {
            L[1] = a[i];
        } else if (a[i] >= L[len]) {
            L[++len] = a[i];
        } else {
            int pos = bsearch(1, len, a[i]);
            L[pos] = a[i];
        }
    }

    printf("%d\n", n-len);
    return 0;
}