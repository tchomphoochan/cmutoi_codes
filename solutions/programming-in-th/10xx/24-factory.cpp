#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int money[n + 1];
    money[0] = 0;
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> money[i];
        sum[i] = sum[i - 1] + money[i];
    }

    int mindiff = 2e9;
    int minsec = 0;
    int minthird = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int first = sum[i - 1];
            int second = sum[j - 1] - sum[i - 1];
            int third = sum[n] - sum[j - 1];

            int mi = min(first, min(second, third));
            int ma = max(first, max(second, third));
            int diff = ma - mi;

            if (diff < mindiff)
            {
                mindiff = diff;
                minsec = i;
                minthird = j;
            }
        }
    }

    cout << minsec << " " << minthird << endl;
}