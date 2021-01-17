#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n;
    cin >> n;

    int rem3 = 0;
    for (int i = 0; i < n.length(); i++)
    {
        rem3 = (rem3 + (n[i] - '0')) % 3;
    }
    
    int rem11 = 0;
    for (int i = n.length() - 1; i >= 0; i -= 2)
    {
        if (i != 0)
            rem11 = (rem11 + (n[i] - '0') + 10 * (n[i - 1] - '0')) % 11;
        else
            rem11 = (rem11 + n[i] - '0') % 11;
    }

    cout << rem3 << " " << rem11 << endl;    

    return 0;
}