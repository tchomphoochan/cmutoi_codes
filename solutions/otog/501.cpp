#include <bits/stdc++.h>

using namespace std;

void print(string s, int sz, char fl = ' ', bool nl = true)
{
    int lf = (sz-s.size())/2;
    for (int i = 0; i < lf; ++i)
        cout << fl;
    cout << s;
    if (fl != ' ') {
        for (int i = 0; i < lf; ++i)
            cout << fl;
    }
    if (nl)
        cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int sz = 2*n+9;

    print("|", sz);
    print("__*__", sz);
    print("/|\\", sz);
    print("/* *\\" ,sz);
    for (int i = 0; i < n; ++i) {
        for (int j = i+3; j <= i+5; ++j) {
            string add;
            add.push_back('/');
            for (int k = 0; k < j; ++k) {
                if (k != 0)
                    add.push_back(' ');
                add.push_back('*');
            }
            add.push_back('\\');
            print(add, sz);
        }
    }
    print("|||", sz);
    print("|||", sz, '_', false);

    return 0;
}