#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int arr[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {

        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        int d;
        for (d = 1; ; ++d) {
            int mn = 0;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (--arr[i] == 0)
                    ++cnt;
                if (arr[i] < arr[mn])
                    mn = i;    
            }
            ++arr[mn];
            if (cnt > 1)
                break;
        }
        printf("%d\n", d);

    }
    return 0;
}