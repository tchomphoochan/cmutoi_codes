#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x[100000];
    int h[100000];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> h[i];
    
    int max = 1;
    int knock = 1;
    char dir = 'R';

    int maxstart = 0;
    int start = 0;

    int i = 0;
    while (i < n)
    {
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (x[i] + h[i] > x[j])
            {
                knock++;
                if (x[j] + h[j] > x[i] + h[i])
                {
                    i = j;
                    break;
                }
            }
            else
            {
                if (knock > max)
                {
                    max = knock;
                    maxstart = start;
                }
                knock = 1;
                i = j;
                start = i;
                break;
            }
        }
        if (j == n)
            break;
    }
    if (knock > max)
    {
        max = knock;
        maxstart = start;
    }

    knock = 1;
    i = n - 1;
    start = i;
    while (i >= 0)
    {
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (x[i] - h[i] < x[j])
            {
                knock++;
                if (x[j] - h[j] < x[i] - h[i])
                {
                    i = j;
                    break;
                }
            }
            else
            {
                if (knock > max || (knock == max && start <= maxstart))
                {
                    dir = 'L';
                    max = knock;
                    maxstart = start;
                }
                knock = 1;
                i = j;
                start = i;
                break;
            }
        }
        if (j == -1)
            break;
    }
    if (knock > max || (knock == max && start <= maxstart))
    {
        dir = 'L';
        max = knock;
        maxstart = start;
    }

    cout << maxstart + 1 << " " << dir;
}