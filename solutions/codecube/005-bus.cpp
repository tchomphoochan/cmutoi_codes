#include <iostream>

using namespace std;

long long gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int n;
    cin >> n;

    long long l;
    cin >> l;

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        l = lcm(l, x);
    }
    
    cout << l << endl;
}