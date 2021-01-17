#include <bits/stdc++.h>
using namespace std;

#define INF (1 << 30)
#define min(a, b) a <= b ? a : b;
#define max(a, b) a >= b ? a : b;

typedef long long ll;

int main()
{
    int roomn, student;
    cin >> roomn >> student;

    int room[10001];
    for (int i = 0; i < student; i++)
    {
        int r, num;
        cin >> r >> num;
        room[num] = r;
    }

    list<int> line;
    char input;
    do
    {
        cin >> input;
        if (input == 'E')
        {
            int num;
            cin >> num;

            bool found = false;
            list<int>::iterator it = line.begin();
            while (it != line.end())
            {
                if (!found && room[*it] == room[num])
                    found = true;
                else if (found && room[*it] != room[num])
                    break;
                ++it;
            }
            line.insert(it, num);
        }
        else if (input == 'D')
        {
            if (!line.empty())
            {
                cout << line.front() << endl;
                line.pop_front();
            }
        }
    } while (input != 'X');

    cout << "0" << endl;
    return 0;
}