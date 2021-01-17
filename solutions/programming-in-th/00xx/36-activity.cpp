#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    long long top = 1, bottom = 1;
    for (int i = n; i > n / 2; i--)
        top *= i;
    if (n % 2 != 0)
        bottom *= (n / 2) + 1;
    for (int i = (n / 2); i > 0; i--)
        bottom *= i;
    long long answer = top / bottom;
    if (n % 2 != 0)
        answer *= 2;
    
    cout << answer << endl;

    return 0;
}