#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int room[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> room[i];

    // fill first row with sum
    int data[k + 1][n + 1];
    data[1][1] = room[1];
    for (int c = 2; c <= n; c++)
        data[1][c] = data[1][c - 1] + room[c];
    
    // fill tables
    for (int r = 2; r <= k; r++)
    {
        for (int c = r; c <= n; c++)
        {
            int low = 2e9;
            // set boundary
            for (int b = r; b <= c; b++)
            {
                int value = data[r - 1][b - 1];
                int psum2 = data[1][c];
                int psum1 = data[1][b - 1];
                low = min(low, max(value, psum2 - psum1));
            }
            data[r][c] = low;
        }
    }

    cout << data[k][n] << endl;
    return 0;
}