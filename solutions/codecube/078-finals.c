#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int x;
    int score[5];

    int sum = 0;
    scanf("%d", &x);
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &score[i]);
        sum += score[i];
    }

    bool pass = false;
    if (sum < x)
        pass = false;
    else if (sum == x)
        pass = true;
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (sum - score[i] == x)
            {
                score[i] = 0;
                pass = true;
                break;
            }
        }
    }

    if (pass)
    {
        for (int i = 0; i < 5; i++)
            printf("%d ", score[i]);
    }
    else
    {
        printf("-1");
    }

    return 0;
}