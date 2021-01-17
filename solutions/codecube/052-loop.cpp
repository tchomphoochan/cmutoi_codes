#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int mid = (n+1)/2;
    for (int i=1; i<=mid; ++i) {
        int cntdokjan = 2*i-1;
        int cntdash = (n-cntdokjan)/2;
        for (int j=0; j < cntdash; ++j)
            printf("-");
        for (int j=0; j < cntdokjan; ++j)
            printf("*");
        for (int j=0; j < cntdash; ++j)
            printf("-");
        printf("\n");
    }
    for (int i=mid-1; i >= 1; --i) {
        int cntdokjan = 2*i-1;
        int cntdash = (n-cntdokjan)/2;
        for (int j=0; j < cntdash; ++j)
            printf("-");
        for (int j=0; j < cntdokjan; ++j)
            printf("*");
        for (int j=0; j < cntdash; ++j)
            printf("-");
        printf("\n");
    }

    return 0;
}