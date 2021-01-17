#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<string> jokes;
    for (int i = 0; i < n; i++)
    {
        string joke;
        cin >> joke;
        jokes.insert(joke);
    }

    for (set<string>::iterator it = jokes.begin(); it != jokes.end(); it++)
    {
        cout << (*it) << endl;
    }

    return 0;
}