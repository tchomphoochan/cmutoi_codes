#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int rowsum[100] = {};
    int colsum[100] = {};
    int allsum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            scanf("%d", &x);
            rowsum[i] += x;
            colsum[j] += x;
            allsum += x;
        }
    }

    int rowadd[100] = {};
    int coladd[100] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            scanf("%d", &x);
            rowadd[i] += x;
            coladd[j] += x;
        }
    }

    int maxval = 0;

    for (int i = 0; i < n; i++)
    {
        int value = allsum - rowsum[i];
        if (i != 0)
            value += rowadd[i - 1];
        if (i != n - 1)
            value += rowadd[i + 1];

        if (value > maxval)
            maxval = value;
    }

    for (int i = 0; i < m; i++)
    {
        int value = allsum - colsum[i];
        if (i != 0)
            value += coladd[i - 1];
        if (i != n - 1)
            value += coladd[i + 1];
        
        if (value > maxval)
            maxval = value;
    }

    printf("%d", maxval);
}