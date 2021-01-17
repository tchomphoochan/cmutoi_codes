#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int lb = i&(-i);
        for (int j = 0; ; ++j) {
            if ((1<<j)&lb) {
                printf("%d: ", i);
                for (int k = 0; k < j+1; ++k)
                    printf("*");
                printf("\n");
                break;
            }
        }
    }

    return 0;
}