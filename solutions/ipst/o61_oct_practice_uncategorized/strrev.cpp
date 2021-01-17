#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

void loopb(int i, int to, int inc, function<bool(int)> act)
{
    if (i == to) return;
    if (!act(i)) return;
    loopb(i+inc, to, inc, act);
}
void loop(int i, int to, int inc, function<void(int)> act)
{
    if (i == to) return;
    act(i);
    loop(i+inc, to, inc, act);
}

int main()
{
    string s;
    cin >> s;
    istringstream iss(s);
    string token;
    vector<string> tokens;
    loopb(0, -1, 1, [&] (int i) {
        if (!getline(iss, token, '_')) return false;
        tokens.push_back(token);
        return true;
    });

    loop(tokens.size()-1, -1, -1, [&] (int i) {
        if (i != tokens.size()-1) cout << "_";
        cout << tokens[i];
    });

    return 0;
}