#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int s;
    int b;
} perket;

int main()
{
    int n;
    cin >> n;
    perket data[n];
    for (int i = 0; i < n; i++)
        cin >> data[i].s >> data[i].b;

    int min = 2e9;

    // loop through each possibility
    for (int i = 1; i <= (1 << n) - 1; i++)
    {
        int sour = 1;
        int bitter = 0;

        // flag checking
        for (int j = 0; (1 << j) <= (1 << (n - 1)); j++)
        {
            if (i & (1 << j))
            {
                sour *= data[j].s;
                bitter += data[j].b;
            }
        }

        int diff = abs(sour - bitter);
        if (diff < min)
            min = diff;
    }

    cout << min << endl;

    return 0;
}