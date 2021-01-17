#include <iostream>
#include <map>

using namespace std;

int main()
{
    int k, n, m;
    cin >> k >> n >> m;

    multimap<int, int> stairs;
    while (m--)
    {
        int s, e;
        cin >> s >> e;
        stairs.insert(pair<int, int>(e, s));
    }

    int highest = 1;
    int shortest[n + 1];
    shortest[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        shortest[i] = 2e9;
        pair<multimap<int, int>::iterator, multimap<int, int>::iterator> range = stairs.equal_range(i);
        for (multimap<int, int>::iterator it = range.first; it != range.second; ++it)
        {
            if (shortest[it->second] + 1 < shortest[i])
            {
                shortest[i] = shortest[it->second] + 1;
            }
        }
        if (shortest[i] <= k)
            highest = i;
    }

    cout << highest << endl;
}
