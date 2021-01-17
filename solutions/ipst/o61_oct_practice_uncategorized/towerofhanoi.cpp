#include <bits/stdc++.h>

using namespace std;

void solve(int n, int from, int to, int aux)
{
    if (n == 1) {
        printf("%d -> %d\n", from, to);
    } else {
        solve(n-1, from, aux, to);
        solve(1, from, to, aux);
        solve(n-1, aux, to, from);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    solve(n, 1, 3, 2);
    return 0;
}