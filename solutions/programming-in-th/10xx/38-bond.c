#include <stdio.h>
#include <math.h>

int n;
double chance[20][20];
double best[1 << 20] = {};

int countBit(int i)
{
    //int count = 0;
    //for (int i = 0; i < n; i++)
    //{
        //if (((1 << i) & x) != 0)
            //count++;
    //}
    //return count;

    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c;
            scanf("%d", &c);
            chance[i][j] = c * 0.01;
        }
    }

    for (int i = 1; i < (1 << n); i++)
    {
        double elem = log2(i);
        if (floor(elem) == elem)
        {
            best[i] = chance[0][(int)elem];
            continue;
        }
        
        double max = 0;
        for (int j = 0; j < n; j++)
        {
            int bit = (1 << j);
            if ((bit & i) == 0)
                continue;
            double bitelem = chance[countBit(i) - 1][j];

            int search = i - bit;
            if (bitelem * best[search] > max)
                max = bitelem * best[search];
        }
        best[i] = max;
    }

    printf("%.6lf", 100 * best[(1 << n) - 1]);
    return 0;
}