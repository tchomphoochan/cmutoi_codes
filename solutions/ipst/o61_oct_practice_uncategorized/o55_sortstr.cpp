#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> str;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        str.push_back(s);
    }
    sort(str.begin(), str.end());
    for (int i = 0; i < n; ++i)
        cout << str[i] << "\n";

    return 0;
}