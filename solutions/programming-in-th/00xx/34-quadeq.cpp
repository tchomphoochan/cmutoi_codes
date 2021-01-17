#include <bits/stdc++.h>
using namespace std;

set<int> halffactorize(int n)
{
    set<int> result;
    for (int i = 1; i <= abs(n); i++)
    {
        if (n % i == 0)
        {
            result.insert(i);
        }
    }
    return result;
}

set<int> factorize(int n)
{
    set<int> result = halffactorize(n);
    for (set<int>::iterator it = result.begin(); it != result.end(); it++)
        result.insert(-(*it));
    return result;
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    set<int> Afactor = halffactorize(A);
    set<int> Cfactor = factorize(C);
    
    if (C == 0)
    {
        cout << "1 0 " << A << " " << B << endl;
        return 0;
    }
    if (B == 0)
    {
        if (C > 0)
        {
            cout << "No Solution" << endl;
            return 0;
        }

        double a = sqrt(A), c = sqrt(-C);
        if (floor(a) != a || floor(c) != c)
        {
            cout << "No Solution" << endl;
            return 0;
        }

        cout << a << " -" << c << " " << a << " " << c << endl;
        return 0;
    }

    for (set<int>::iterator at = Afactor.begin(); at != Afactor.end(); at++)
    {
        int a = (*at);
        int c = A / a;
        for (set<int>::iterator ct = Cfactor.begin(); ct != Cfactor.end(); ct++)
        {
            int b = (*ct);
            int d = C / b;

            if (b * c + a * d == B)
            {
                cout << a << " " << b << " " << c << " " << d << endl;
                return 0;
            }
        }
    }

    cout << "No Solution" << endl;
    return 0;
}