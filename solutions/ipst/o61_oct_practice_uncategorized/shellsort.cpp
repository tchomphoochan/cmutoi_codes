#include <bits/stdc++.h>
using namespace std;
int arr[100010];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    for (int k = 1; ; ++k) {
        int s = n/(1<<k);
        if (s < 1) s = 1;
        for (int i = 0; i < n; ++i)
            for (int j = i-s; j >= 0; --j)
                if (arr[j] > arr[j+s]) swap(arr[j], arr[j+s]);
        if (s == 1) break;
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    return 0;
}