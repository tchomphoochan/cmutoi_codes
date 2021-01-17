#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

int pd[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int d = min(min(i, j), min(n-1-i, n-1-j));
            ++pd[d];
            if (n%4 == 0 && i == (n-1)/2 && j == n/2) {
                printf("-");
            } else {
                if ((d % 2 == 0) == (pd[d] == 2))
                    printf("-");
                else
                    printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}