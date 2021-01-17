#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int m, n;
    scanf("%d%d", &m, &n);
    char place[100][100]; // FIX THIS

    for (int i = 0; i < m; i++)
    {
        scanf(" ");
        for (int j = 0; j < n; j++)
            scanf("%c", &place[i][j]);
    }

    int firstT, firstL, firstB, firstR;
    bool keep = true;
    for (int i = 0; i < m && keep; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (place[i][j] != 'x')
                continue;
            
            firstT = i;
            firstL = j;

            // from top left
            bool keep2 = true;
            while (keep2)
            {
                if ((++i >= m) | (++j >= n))
                    break;

                for (int y = i, x = j; x >= firstL; --x, --y)
                {
                    if (place[i][x] != 'x' || place[y][j] != 'x')
                    {
                        keep2 = false;
                        break;
                    }
                }
            }

            firstB = i - 1;
            firstR = j - 1;
            keep = false;
            break;
        }
    }

    int secondT, secondL, secondB, secondR;
    bool sameMatch = false;
    keep = true;
    for (int i = m - 1; i >= 0 && keep; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            if (place[i][j] != 'x')
                continue;

            if (i == firstB && j == firstR)
            {
                sameMatch = true;
            }
            else
            {
                // from bottom right
                secondB = i;
                secondR = j;

                bool keep2 = true;
                while (keep2)
                {
                    if ((--i < 0) | (--j < 0))
                        break;

                    for (int y = i, x = j; x <= secondR; ++x, ++y)
                    {
                        if (place[i][x] != 'x' || place[y][j] != 'x')
                        {
                            keep2 = false;
                            break;
                        }
                    }
                }

                secondT = i + 1;
                secondL = j + 1;

            }

            keep = false;
            break;
        }
    }

    if (sameMatch)
    {
        // scan from top left
        keep = true;
        for (int j = 0; j < firstL && keep; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                if (place[i][j] != 'x')
                    continue;
                
                secondT = i;
                secondL = j;

                bool keep2 = true;
                while (keep2)
                {
                    if ((++i >= m) | (++j >= n))
                        break;

                    for (int y = i, x = j; x >= secondL; --x, --y)
                    {
                        if (place[i][x] != 'x' || place[y][j] != 'x')
                        {
                            keep2 = false;
                            break;
                        }
                    }
                }

                secondB = i - 1;
                secondR = j - 1;
                keep = false;
                break;
            }
        }

        // scan from bottom right
        for (int j = n - 1; j > firstR && keep; --j)
        {
            for (int i = m - 1; i >= 0; --i)
            {
                if (place[i][j] != 'x')
                    continue;

                if (i == firstB && j == firstR)
                {
                    sameMatch = true;
                }
                else
                {
                    // from bottom right
                    secondB = i;
                    secondR = j;

                    bool keep2 = true;
                    while (keep2)
                    {
                        if ((--i < 0) | (--j < 0))
                            break;

                        for (int y = i, x = j; x <= secondR; ++x, ++y)
                        {
                            if (place[i][x] != 'x' || place[y][j] != 'x')
                            {
                                keep2 = false;
                                break;
                            }
                        }
                    }

                    secondT = i + 1;
                    secondL = j + 1;

                }

                keep = false;
                break;
            }
        }
    }

    printf("%d %d %d\n%d %d %d", firstT + 1, firstL + 1, firstB - firstT + 1,
    secondT + 1, secondL + 1, secondB - secondT + 1);
    return 0;
}