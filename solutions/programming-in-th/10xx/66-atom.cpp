#include <iostream>
#include <cmath>
#include <list>

using namespace std;

int main()
{
    int n;
    cin >> n;

    list<int> atom;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        atom.push_back(x);
    }

    int total = 0;
    while (atom.size() > 1)
    {
        list<int>::iterator max = atom.begin();
        int diff = 0;

        list<int>::iterator end = atom.end();
        --end;

        for (list<int>::iterator it = atom.begin(); it != end; )
        {
            int x = *it;
            int y = *(++it);
            int d = abs(x - y);
            if (d > diff)
            {
                max = it;
                diff = d;
            }
        }

        atom.erase(max--);
        atom.erase(max);
        total += diff;
    }

    cout << total << endl;
}