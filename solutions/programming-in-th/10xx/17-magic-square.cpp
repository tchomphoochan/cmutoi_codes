#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int target;
    int diag = 0;
    int diag2 = 0;
    bool fail = false;
    bool used[n * n + 1];
    for (int i = 0; i < n * n + 1; i++)
        used[i] = false;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (!used[x])
                used[x] = true;
            else
            {
                fail = true;
                break;
            }

            if (i == j)
                diag += x;
            if (i == n - j - 1)
                diag2 += x;
            sum += x;
        }

        if (fail)
            break;
        if (i == 0)
            target = sum;
        else if (sum != target)
        {
            fail = true;
            break;
        }
    }

    cout << ((fail || diag != target || diag2 != target) ? "No" : "Yes");
}