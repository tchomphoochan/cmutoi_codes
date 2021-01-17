#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, A[5];
    scanf("%d", &x);
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &A[i]);
        sum += A[i];
    }
    if (sum == x) {
        for (int i = 0; i < 5; ++i)
            printf("%d ", A[i]);
        return 0;
    }
    for (int i = 0; i < 5; ++i) {
        if (sum-A[i] == x) {
            for (int j = 0; j < 5; ++j)
                printf("%d ", i == j ? 0 : A[j]);
            return 0;
        }
    }
    printf("-1");
    
    return 0;
}