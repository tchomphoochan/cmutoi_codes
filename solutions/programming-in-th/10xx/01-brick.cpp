#include <iostream>
#include <functional>
using namespace std;

// game data
int row, column;
char board[5][5];
int score = 0;

#define boundary(a, b) (a >= 0 && a < row && b >= 0 && b < column)

int attemptMove(int r, int c, char type)
{
    if (!boundary(r, c))
        return -1;
    char box = board[r][c];
    if (box == '-' || box == '#')
        return -1;
    
    int newC = (type == 'L' ? c - 1 : c + 1);
    if (!boundary(r, newC) || board[r][newC] != '-')
        return -1;
    
    swap(board[r][c], board[r][newC]);
    return newC;
}

int allgravity()
{
    for (int i = 0; i )
}

int gravity(int r, int nc) //, int oc)
{
    // move newly moved box down
    int newR = r;
    while (r < row && board[newR + 1][nc] == '-')
        newR += 1;
    swap(board[r][nc], board[newR][nc]);

    /* // move blocks on old column down
    for (int i = r; i > 0; i--)
    {
        if (board[i][oc] == '-' && board[i - 1][oc] != '#')
            swap(board[i][oc], board[i - 1][oc]);
    } */

    return newR;
}

#define check(r, c) (boundary(r, c) && board[r][c] == type)
int clearBoard(int r, int c)
{
    char type = board[r][c];
    board[r][c] = '-';
    int score = 5;

    if (check(r, c - 1))
        score += clearBoard(r, c - 1);
    if (check(r, c + 1))
        score += clearBoard(r, c + 1);
    if (check(r - 1, c))
        score += clearBoard(r - 1, c);
    if (check(r + 1, c))
        score += clearBoard(r + 1, c);
    
    return score;
}

void printBoard()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << board[i][j];
            if (j != column - 1)
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    // board input
    cin >> row >> column;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cin >> board[i][j];
    }

    // game input
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // input
        int r, c;
        char type;
        cin >> r >> c >> type;

        // execute
        int newC = attemptMove(r, c, type);
        if (newC == -1)
        {
            score -= 5;
        }
        else
        {
            int newR = gravity(r, newC) //, c);
            score += clearBoard(newR, newC);
            allgravity();
        }
    }
    
    // print final output
    cout << score << endl;
    printBoard();

    return 0;
}