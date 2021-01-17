#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int cnt1310 = 0, cnt10 = 0, cnt13 = 0;
    int ls = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (ls==13 && x==10)
            ++cnt1310;
        if (x == 10)
            ++cnt10;
        if (x == 13)
            ++cnt13;
        ls = x;
    }
    printf("%d %d %d\n", cnt1310+1, cnt10+1, cnt13+1);

    return 0;
}