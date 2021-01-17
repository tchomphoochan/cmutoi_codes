#include <stdio.h>
#include <algorithm>
using namespace std;

int cut[500010];
int main()
{
    int n, b, cnt = 0;
    scanf("%d%d", &n, &b);
    for (int i = 2; i <= n; i++)
    {
        if (cut[i])
            continue;
        ++cnt;
        for (int j = i; j <= n; j += i)
            cut[j] = 1;
    }

    printf("%d", max(0, cnt-b));

    return 0;
}