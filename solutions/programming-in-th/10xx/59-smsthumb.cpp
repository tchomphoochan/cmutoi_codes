#include <iostream>

using namespace std;

char getPress(int x, int y, int m)
{
    static string buttons[3][3] =
    {
        { "\b", "ABC", "DEF" },
        { "GHI", "JKL", "MNO" },
        { "PQRS", "TUV", "WXYZ" }
    };

    return buttons[y][x][(m - 1) % buttons[y][x].length()];
}

int main()
{
    ios::sync_with_stdio(false);

    string text;
    text.reserve(80);

    int n, s, m;
    cin >> n >> s >> m;

    int x = (s - 1) % 3;
    int y = (s - 1) / 3;
    char p = getPress(x, y, m);
    if (p != '\b')
        text.push_back(p);

    for (int i = 0; i < n - 1; i++)
    {
        int h, v, m;
        cin >> h >> v >> m;
        x += h;
        y += v;
        char picked = getPress(x, y, m);

        if (picked == '\b')
        {
            if (text.length() >= m)
                text.erase(text.end() - m, text.end());
            else
                text.clear();
        }
        else
        {
            text.push_back(picked);
        }
    }

    cout << (text.empty() ? "null" : text);
}