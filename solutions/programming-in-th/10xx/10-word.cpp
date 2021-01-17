#include <bits/stdc++.h>
using namespace std;

#define INF (1 << 30)
#define min(a, b) a <= b ? a : b;
#define max(a, b) a >= b ? a : b;

typedef unsigned uint;
typedef long long ll;

typedef struct
{
    int x;
    int y;
} Pair;

Pair empt = {-1, -1};

int m, n;
vector< vector<char> > table;
string text;

#define boundary(i, j) (i >= 0 && i < m && j >= 0 && j < n)

bool checkDirection(int i, int j, int dx, int dy)
{
    for (int a = 0; a < text.length(); a++)
    {
        if (!boundary(i + a * dx, j + a * dy) || table[i + a * dx][j + a * dy] != text[a])
            return false;
    }
    return true;
}

bool checkPoint(int i, int j)
{
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0)
                continue;
            if (checkDirection(i, j, dx, dy))
                return true;
        }
    }
    return false;
}

Pair checkText()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Pair ret = {i, j};
            if (checkPoint(i, j))
                return ret;
        }
    }

    return empt;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        vector<char> row;
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            row.push_back(tolower(c));
        }
        table.push_back(row);
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> text;
        for (int i = 0; i < text.length(); i++)
            text[i] = tolower(text[i]);

        Pair result = checkText();
        cout << result.x << " " << result.y << endl;
    }

    return 0;
}