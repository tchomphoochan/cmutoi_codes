#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    char t;
    string s;
    list<string> li;
    auto ptr = li.begin();

    cin >> n;
    while (n--) {
        cin >> t;
        if (t == 'i') {
            cin >> s;
            li.insert(ptr, s);
        } else if (t == 'l') {
            if (ptr != li.begin())
                --ptr;
        } else if (t == 'r') {
            if (ptr != li.end())
                ++ptr;
        } else if (t == 'b') {
            if (ptr != li.begin())
                ptr = li.erase(prev(ptr));
        } else if (t == 'd') {
            if (ptr != li.end())
                ptr = li.erase(ptr);
        }
    }

    for (auto w : li)
        cout << w << " ";

    return 0;
}