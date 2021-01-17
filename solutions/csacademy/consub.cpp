#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

int arr[N], v1[N*10], v2[N*10];

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v1[x] = max(v1[x], v1[x-1]+1);
        v2[x] = max(v2[x], max(v2[x-1]+1, v1[x-2]+2));
        ans = max(ans, max(v1[x], v2[x]));
    }
    printf("%d\n", ans);

    return 0;
}
