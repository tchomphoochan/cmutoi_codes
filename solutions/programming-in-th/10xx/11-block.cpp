#include <iostream>
#include <queue>

using namespace std;

int m, n;
char block[5][5];
#define boundary(y, x) (y >= 0 && y < m && x >= 0 && x < n)

int disappear(int r, int c)
{
    char x = block[r][c];

    if ((boundary(r, c - 1) && block[r][c - 1] == x)
       || (boundary(r, c + 1) && block[r][c + 1] == x)
       || (boundary(r - 1, c) && block[r - 1][c] == x)
       || (boundary(r + 1, c) && block[r + 1][c] == x))
    {
        int score = 0;
        queue<pair<int, int> > coord;
        coord.push(pair<int, int>(r, c));
        while (!coord.empty())
        {
            r = coord.front().first;
            c = coord.front().second;
            score += 5;
            block[r][c] = '-';

            if (boundary(r, c - 1) && block[r][c - 1] == x)
                coord.push(pair<int, int>(r, c - 1));
            if (boundary(r, c + 1) && block[r][c + 1] == x)
                coord.push(pair<int, int>(r, c + 1));
            if (boundary(r - 1, c) && block[r - 1][c] == x)
                coord.push(pair<int, int>(r - 1, c));
            if (boundary(r + 1, c) && block[r + 1][c] == x)
                coord.push(pair<int, int>(r + 1, c));
            
            coord.pop();
        }
            
        return score;
    }

    return 0;
}

int main()
{
    // get blocks
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> block[i][j];
    }
    
    // get operations
    int score = 0;
    int o;
    cin >> o;
    while (o--)
    {
        int r, c;
        char d;
        cin >> r >> c >> d;

        // move
        if (!boundary(r, c) || block[r][c] == '#' || block[r][c] == '-')
        {
            score -= 5;
            continue;
        }
        if (d == 'L')
        {
            if (!boundary(r, c - 1) || block[r][c - 1] != '-')
            {
                score -= 5;
                continue;
            }

            swap(block[r][c], block[r][c - 1]);
        }
        if (d == 'R')
        {
            if (!boundary(r, c + 1) || block[r][c + 1] != '-')
            {
                score -= 5;
                continue;
            }

            swap(block[r][c], block[r][c + 1]);
        }

        int addScore;
        do
        {
            // fall all
            // start from almost bottom row
            for (int i = m - 2; i >= 0; i--)
            {
                for (int j = 0; j < n; j++)
                {
                    if (block[i][j] == '-' || block[i][j] == '#')
                        continue;

                    int x = i;
                    // move down
                    while (boundary(x + 1, j) && block[x + 1][j] == '-')
                    {
                        swap(block[x][j], block[x + 1][j]);
                        x++;
                    }
                }
            }

            // disappear
            addScore = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (block[i][j] != '-' && block[i][j] != '#')
                        addScore += disappear(i, j);
                }
            }

            score += addScore;
        }
        while (addScore > 0);
    }

    cout << score << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << block[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << endl;
    }
}