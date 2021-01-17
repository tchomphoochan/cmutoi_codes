#include <iostream>

using namespace std;

typedef long long ll;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;
    
    int data[n];
    cin >> data[0];

    int g = data[0];
    for (int i = 1; i < n; i++)
    {
        cin >> data[i];
        g = gcd(g, data[i]);
    }

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += data[i] / g;
    }

    cout << sum << endl;
}