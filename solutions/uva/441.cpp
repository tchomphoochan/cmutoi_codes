#include <bits/stdc++.h>

using namespace std;

const int N = 15;
int arr[N];

int main()
{
    int C = 0;
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;    
        if (C != 0)
            printf("\n");
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        for (int a = 0; a < n; ++a) {
            for (int b = a+1; b < n; ++b) {
                for (int c = b+1; c < n; ++c) {
                    for (int d = c+1; d < n; ++d) {
                        for (int e = d+1; e < n; ++e) {
                            for (int f = e+1; f < n; ++f) {
                                printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
                            }
                        }
                    }
                }
            }
        }
        ++C;
    }

    return 0;
}