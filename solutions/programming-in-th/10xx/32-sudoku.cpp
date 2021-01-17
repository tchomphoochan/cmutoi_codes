#include <iostream>

using namespace std;

void getSudoku(int num[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cin >> num[i][j];
    }
}

bool checkSudoku(int start[9][9], int player[9][9])
{
    // horizontal
    for (int i = 0; i < 9; i++)
    {
        bool has[10]; // ignore 0
        for (int j = 0; j < 10; j++)
            has[j] = false;
        for (int j = 0; j < 9; j++)
        {
            // match start
            if (start[i][j] != 0 && start[i][j] != player[i][j])
                return false;

            if (!has[player[i][j]])
                has[player[i][j]] = true;
            else
                return false;
        }
    }

    // vertical
    for (int i = 0; i < 9; i++)
    {
        bool has[10]; // ignore 0
        for (int j = 0; j < 10; j++)
            has[j] = false;
        for (int j = 0; j < 9; j++)
        {
            if (!has[player[j][i]])
                has[player[j][i]] = true;
            else
                return false;
        }
    }
    
    // block
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            bool has[10];
            for (int k = 0; k < 10; k++)
                has[k] = false;

            for (int y = i; y < i + 3; y++)
            {
                for (int x = j; x < j + 3; x++)
                {
                    if (!has[player[y][x]])
                        has[player[y][x]] = true;
                    else
                        return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int start[9][9];
    getSudoku(start);

    for (int i = 1; i <= n; i++)
    {
        int player[9][9];
        getSudoku(player);

        if (checkSudoku(start, player))
            cout << i << endl;
    }

    cout << "END" << endl;
}