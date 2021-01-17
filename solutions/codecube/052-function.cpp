#include <stdio.h>

void repeat(char c, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%c", c);
}

void printline(int n, int i)
{
    int cntdokjan = 2*i-1;
    int cntdash = (n-cntdokjan)/2;
    repeat('-', cntdash);
    repeat('*', cntdokjan);
    repeat('-', cntdash);
    printf("\n");
}

void printpattern(int n)
{
    int mid = (n+1)/2;
    for (int i = 1; i <= mid; ++i)
        printline(n, i);
    for (int i = mid-1; i >= 1; --i)
        printline(n, i);
}

int main()
{
    int n;
    scanf("%d", &n);
    printpattern(n);

    return 0;
}