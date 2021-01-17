#include <iostream>

using namespace std;

char board[8][8];

void fill(int row, int col, char player, int dr, int dc)
{
    char opponent = (player == 'X' ? 'O' : 'X');

    int r = row + dr;
    int c = col + dc;

    if (board[r][c] != opponent)
        return;

    #define boundary(y, x) (y >= 0 && y < 8 && x >= 0 && x < 8)
    while (boundary(r, c) && board[r][c] != player)
    {
        r += dr;
        c += dc;
    }

    if (boundary(r, c) && board[r][c] == player)
    {
        // fill
        board[row][col] = player;
        int r = row + dr;
        int c = col + dc;
        while (board[r][c] == opponent)
        {
            board[r][c] = player;
            r += dr;
            c += dc;
        }
    }
}

void place(int row, int col, char player)
{
    char opponent = (player == 'X' ? 'O' : 'X');

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            
            fill(row, col, player, i, j);
        }
    }
}

int main()
{
    // init
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            board[i][j] = '.';
    }
    board[3][3] = board[4][4] = 'O';
    board[3][4] = board[4][3] = 'X';

    // input
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char colChar;
        int row, col;
        cin >> colChar >> row;

        col = colChar - 'a';
        row--;

        place(row, col, i % 2 == 0 ? 'X' : 'O');
    }

    // output
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << board[i][j];
        cout << endl;
    }
}