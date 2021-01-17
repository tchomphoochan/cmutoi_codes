#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int> > li;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == 'P')
        {
            int x;
            cin >> x;
            li.push(x);
        }
        else
        {
            int val;
            if (li.empty())
                val = -1;
            else
            {
                val = li.top();
                li.pop();
            }
            cout << val << endl;
        }
    }
}