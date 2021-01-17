#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int m = min(min(i, j), min(n-1-i, n-1-j));
            if (m&1)
                printf("-");
            else
                printf("*");
        }
        printf("\n");
    }

    return 0;
}