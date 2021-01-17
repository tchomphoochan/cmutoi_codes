#include <iostream>
#include <algorithm>

using namespace std;

struct Point
{
    int row;
    int col;

    Point(int r, int c)
    {
        row = r;
        col = c;
    }

    bool operator==(const Point &other) const
    {
        return row == other.row && col == other.col;
    }
};

bool validPath(const Point position[5], const Point &pos, int n)
{
    if (pos.row < 0 || pos.row >= n || pos.col < 0 || pos.col >= n)
        return false;

    for (int i = 1; i <= 4; i++)
    {
        const Point &p = position[i];
        if (p == pos)
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    // initialize
    
    int table[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            table[i][j] = 0;
    }

    Point position[5] =
    {
        Point(-1, -1),
        Point(0, n - 1),
        Point(n - 1, n - 1),
        Point(n - 1, 0),
        Point(0, 0)
    };

    for (int i = 1; i <= 4; i++)
    {
        Point &pos = position[i];
        table[pos.row][pos.col] = i;
    }
    
    int score[5] = { 0, 1, 1, 1, 1 };

    // commands
    char direction[k][5];
    for (int j = 1; j <= 4; j++)
    {
        for (int i = 0; i < k; i++)
        {
            char way;
            cin >> way;
            direction[i][j] = way;
        }
    }

    // execute
    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            Point &pos = position[j];
            char way = direction[i][j];

            Point another = pos;
            switch (way)
            {
                case 'N': another.row--; break;
                case 'E': another.col++; break;
                case 'S': another.row++; break;
                case 'W': another.col--; break;
            }

            if (validPath(position, another, n))
            {
                int removed = table[another.row][another.col];
                table[another.row][another.col] = j;
                score[j]++;
                score[removed]--;
                pos = another;
            }
        }
    }

    // null result
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == 0)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    // valid result
    int maxScore = -1;
    int people = 0;
    int tops[4];
    for (int i = 1; i <= 4; i++)
    {
        if (score[i] > maxScore)
        {
            maxScore = score[i];
            people = 1;
            tops[0] = i;
        }
        else if (score[i] == maxScore)
        {
            tops[people++] = i;
        }
    }

    cout << people << " " << maxScore << endl;
    for (int i = 0; i < people; i++)
        cout << tops[i] << endl;

    return 0;
}