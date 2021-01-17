#include <iostream>

using namespace std;

int main()
{
    int N, k;
    cin >> N >> k;

    int count[N + 1];
    count[0] = 1;
    count[1] = 1;

    int sum[N + 1];
    sum[0] = 1;
    sum[1] = 2; 

    for (int n = 2; n <= N; n++)
    {
        int answer = 0;
        if (n > k)
        {
            // sum from count[n - k] to count[n - 1]
            //for (int i = n - k; i <= n - 1; i++)
            //    answer += count[i];
            answer = sum[n - 1] - sum[n - k - 1];
        }
        else
        {
            // sum from count[0] to count[n - 1]
            //for (int i = 0; i <= n - 1; i++)
            //   answer += count[i];
            answer = sum[n - 1];
        }
        count[n] = answer % 2009;
        if (count[n] < 0)
            count[n] += 2009;
        sum[n] = (sum[n - 1] + count[n]) % 2009;
        if (sum[n] < 0)
            sum[n] += 2009;
    }

    cout << count[N] << endl;
}