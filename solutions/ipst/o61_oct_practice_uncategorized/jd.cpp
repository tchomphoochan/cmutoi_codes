#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;;

const int N = 100010;

int main()
{
    while (true) {

        int n;
        scanf("%d", &n);
        if (n == 0)
            break;    
        pii arr[N] = {};
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &arr[i].first, &arr[i].second);
        sort(arr+1, arr+n+1);

        int len = 1;
        int lis[N] = {0, arr[1].second};
        for (int i = 2; i <= n; ++i) {
            if (arr[i].second >= lis[len]) {
                lis[++len] = arr[i].second;
            } else if (arr[i].second < lis[1]) {
                lis[1] = arr[i].second;
            } else {
                int p = upper_bound(lis+1, lis+len+1, arr[i].second)-lis;
                lis[p] = arr[i].second;
            }
        }
        printf("%d\n", len);

    }

    return 0;
}