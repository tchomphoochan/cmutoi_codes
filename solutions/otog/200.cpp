#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if (a+b == c)
        printf("1");
    else if (a*a + b*b == c*c)
        printf("2");
    else
        printf("NO");
    return 0;
}