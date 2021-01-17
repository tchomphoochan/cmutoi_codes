#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+10;

unsigned arr[N];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%u", &arr[i]);
    sort(arr, arr+n);

    bool did = false;
    unsigned ans = 0;
    for (int i = 31; i >= 0; --i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (((1U<<i)&arr[j]) && (!did || ((ans | arr[j]) == arr[j])))
                ++cnt;
        }
        if (cnt >= 2) {
            ans |= (1U<<i);
            did = true;
        }
    }
    printf("%d", ans);

    return 0;
}