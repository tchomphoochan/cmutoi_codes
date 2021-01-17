#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int m = a.length();
    int n = b.length();

    int ln[m][n];    
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int i = 0;           
            while (r - i >= 0 && c - i >= 0 && a[r - i] == b[c - i])
                i++;
            if (r - 1 >= 0)
                i = max(i, ln[r - 1][c]);
            if (c - 1 >= 0)
                i = max(i, ln[r][c - 1]);
            ln[r][c] = i;
        }
    }

    int r = m - 1;
    int c = n - 1;
    while (true)
    {
        bool traversed = false;
        if (r - 1 >= 0 && ln[r - 1][c] == ln[r][c])
        {
            traversed = true;
            r--;
        }
        else if (c - 1 >= 0 && ln[r][c - 1] == ln[r][c])
        {
            traversed = true;
            c--;
        }

        if (!traversed)
            break;
    }

    cout << a.substr(r - ln[r][c] + 1, ln[r][c]) << endl;
}