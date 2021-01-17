#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 40;

ll len[N];

char solve(int n, int k)
{
    if (n == 0)
        return 'a';
    else if (n == 1)
        return 'b';
    else if (n == 2)
        return 'c';
    else if (k <= len[n-1])
        return solve(n-1, k);
    else if (k <= len[n-1]+len[n-2])
        return solve(n-2, k-len[n-1]);
    else
        return solve(n-3, k-len[n-1]-len[n-2]);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    len[0] = len[1] = len[2] = 1;
    for (int i = 3; i <= n; ++i)
        len[i] = len[i-1]+len[i-2]+len[i-3];
    if (k > len[n])
        printf("-1\n");
    else
        printf("%c\n", solve(n, k));

    return 0;
}
