#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int ans;
    int count = 0;
    int lim = 1 << 20;
    for (int i = 0; i < lim; ++i)
    {
        ans = n;
        count = 0;
        for (int j = 0; j < 20; ++j)
        {
            if (i & (1 << j))
            {
                ans += (int) pow(3, j);
                ++count;
            }
        }

        int newN = ans;
        bool pass = true;
        for (int j = 19; j >= 0; --j)
        {
            if (pow(3, j) > newN)
                continue;    
            
            int divi = newN / pow(3, j);
            if (divi > 1 || (i & (1 << j) && divi == 1))
            {
                pass = false;
                break;
            }
            
            newN %= (int) pow(3, j);
            ++count;
        }

        if (pass)
            break;
    }

    printf("%d %d", count, ans);
    return 0;
}