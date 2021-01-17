#include <bits/stdc++.h>

using namespace std;

int g(int n, int k)
{
    if (n == 1)
        return 0;
    if (1 < n && n < k)
        return (g(n-1,k)+k) % n;
    int np = n-(n/k);
    return (k*( g(np, k)- n%k))/(k-1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << ((g(n, k)+n)%n + 1);
    return 0;
}