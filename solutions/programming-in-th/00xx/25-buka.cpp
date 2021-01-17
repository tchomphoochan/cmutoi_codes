#include <iostream>
#include <string>

using namespace std;

inline void printZero(int n)
{
    for (int i = 0; i < n; i++)
        cout << "0";
}

int main()
{
    string as, bs, op;
    cin >> as >> op >> bs;
    
    int a = as.length() - 1;
    int b = bs.length() - 1;

    if (op == "*")
    {
        cout << "1";
        printZero(a + b);
    }
    else
    {
        if (a == b)
        {
            cout << "2";
            printZero(a);
        }
        else
        {
            if (b > a)
            {
                int temp = b;
                b = a;
                a = temp;
            }
            cout << 1;
            printZero(a - b - 1);
            cout << 1;
            printZero(b);
        }
    }

    cout << endl;
    return 0;
}