#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    char str[101] = {};
    gets(str);
    int n = strlen(str);

    int k;
    scanf("%d", &k);

    int N = 0;
    int W = 0;
    int E = 0;
    int S = 0;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == 'N')
            ++N;
        else if (str[i] == 'W')
            ++W;
        else if (str[i] == 'E')
            ++E;
        else
            ++S;
    }

    int max = 0;
    for (int dN = 0; dN <= k && dN <= N; ++dN)
    {
        int kdN = k - dN;
        for (int dW = 0; dW <= kdN && dW <= W; ++dW)
        {
            int kdW = kdN - dW;
            for (int dE = 0; dE <= kdW && dE <= E; ++dE)
            {
                int dS = kdW - dE;
                if (dS > S)
                    continue;

                int y = abs((N - dN) - (S - dS));
                int x = abs((E - dE) - (W - dW));

                if (y + x > max)
                     max = y + x;
            }
        }
    }

    printf("%d", 2 * max);

    return 0;
}