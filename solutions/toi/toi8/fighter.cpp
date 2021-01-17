/**
 * toi8_fighter
 * 
 * aquablitz11 (2016)
 */

#include <stdio.h>

int main(void)
{
    int p;
    scanf("%d", &p);

    int pe = p;
    int po = p;
    int count = 0;
    p *= 2;

    while (p-- >= 0)
    {
        int atk;
        scanf("%d", &atk);
        if (atk % 2 == 0)
        {
            if (count < 0)
                count = 1;
            else
                count++;
            po -= (count >= 3 ? 3 : 1);
            if (po <= 0)
            {
                printf("0\n%d", atk);
                break;
            }
        }
        else
        {
            if (count > 0)
                count = -1;
            else
                count--;
            pe -= (count <= -3 ? 3 : 1);
            if (pe <= 0)
            {
                printf("1\n%d", atk);
                break;
            }
        }
    }

    return 0;
}