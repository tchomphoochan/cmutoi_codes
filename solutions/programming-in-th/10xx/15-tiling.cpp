#include <iostream>

using namespace std;

int main()
{
    // input
    int n;
    cin >> n;
    int tile[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> tile[i][j];
    }

    // survey each block as center of tile
    int correctCounter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int curNum = tile[i][j];
            int adhorX = -1;
            int adhorY = -1;
            int adverX = -1;
            int adverY = -1;

            #define boundary(i, j) (i >= 0 && i < n && j >= 0 && j < n)

            // horizontal
            if (boundary(i, j - 1) && tile[i][j - 1] == curNum)
            {
                adhorY = i;
                adhorX = j - 1;
            }
            if (boundary(i, j + 1) && tile[i][j + 1] == curNum)
            {
                if (adhorY != -1)
                {
                    adhorY = -1;
                    adhorX = -1;
                }
                else
                {
                    adhorY = i;
                    adhorX = j + 1;
                }
            }

            // vertical
            if (boundary(i - 1, j) && tile[i - 1][j] == curNum)
            {
                adverY = i - 1;
                adverX = j;
            }
            if (boundary(i + 1, j) && tile[i + 1][j] == curNum)
            {
                if (adverY != -1)
                {
                    adverY = -1;
                    adverX = -1;
                }
                else
                {
                    adverY = i + 1;
                    adverX = j;
                }
            }

            // if exactly one of horizontal and vertical adjacent tiles are found
            // attempt to find other adjacents
            if (adhorX != -1 && adverX != -1)
            {
                bool horleft = (adhorX - 1 == j || !boundary(adhorX - 1, adhorY) || tile[adhorY][adhorX - 1] != curNum);
                bool horright = (adhorX + 1 == j || !boundary(adhorX + 1, adhorY) || tile[adhorY][adhorX + 1] != curNum);
                bool horup = (!boundary(adhorX, adhorY - 1) || tile[adhorY - 1][adhorX] != curNum);
                bool hordown = (!boundary(adhorX, adhorY + 1) || tile[adhorY + 1][adhorX] != curNum);
                bool verleft = (!boundary(adverX - 1, adverY) || tile[adverY][adverX - 1] != curNum);
                bool verright = (!boundary(adverX + 1, adverY) || tile[adverY][adverX + 1] != curNum);
                bool verup = (adverY - 1 == i || !boundary(adverX, adverY - 1) || tile[adverY - 1][adverX] != curNum);
                bool verdown = (adverY + 1 == i || !boundary(adverX, adverY + 1) || tile[adverY + 1][adverX] != curNum);

                if (horleft & horright && horup && hordown && verleft && verright && verup && verdown)
                    correctCounter++;
            }
        }
    }

    cout << correctCounter << endl;

    return 0;
}