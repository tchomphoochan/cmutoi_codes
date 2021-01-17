#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int n, m;
int arr[N];

int count(int k)
{
    int group = 1, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt+arr[i] > k) {
            ++group;
            cnt = 0;
        }
        cnt += arr[i];
    }
    return group;
}

int main()
{
    scanf("%d%d", &n, &m);

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        mx = max(mx, arr[i]);
    }
    
    if (count(mx) < m) {
        printf("IMPOSSIBLE");
        return 0;
    }

    int l = mx;
    int r = 2e9;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (count(mid) >= m)
            l = mid;
        else
            r = mid-1;
    }

    printf("%d", r);
    return 0;
}