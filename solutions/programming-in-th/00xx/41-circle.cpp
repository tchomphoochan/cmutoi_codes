#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    double ans;
    if (n == 1)
        ans = 2;
    else if (n == 3)
        ans = (5.464102)/2+1;
    else if (n % 2 == 0)
        ans = n;
    else
        ans = (n-1)+1.464102;
    printf("%.6lf", ans);

    return 0;
}