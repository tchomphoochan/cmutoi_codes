#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "error" << endl;
    }
    else
    {
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            for (int j = 0; j < i; j++)
                cout << " ";
            for (int j = 0; j < n - 2 * i; j++)
                cout << "*";
            for (int j = 0; j < i; j++)
                cout << " ";
            cout << endl;
        }
        for (int i = (n - 3) / 2; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
                cout << " ";
            for (int j = 0; j < n - 2 * i; j++)
                cout << "*";
            for (int j = 0; j < i; j++)
                cout << " ";
            cout << endl;
        }
    }
}