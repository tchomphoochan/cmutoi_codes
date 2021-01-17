#include <stdio.h>
#include <stdbool.h>

int n, k;
int leftInEven[2000000] = {};
int leftInOdd[2000000] = {};
int rightInEven[2000000] = {};
int rightInOdd[2000000] = {};

#define leftEven(i) (leftInEven[1000000 + i])
#define leftOdd(i) (leftInOdd[1000000 + i])
#define rightEven(i) (rightInEven[1000000 + i])
#define rightOdd(i) (rightInOdd[1000000 + i])

int main(void)
{
    scanf("%d%d", &n, &k);

    int sum = 0;
    bool left = true;
    leftEven(0) = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        int diff = (x > k ? 1 : (x < k ? -1 : 0));
        sum += diff;

        if (diff == 0)
            left = false;

        if (left)
        {
            if (i % 2 != 0)
                leftEven(sum) += 1;
            else
                leftOdd(sum) += 1;
        }
        else
        {
            if (i % 2 != 0)
                rightEven(sum) += 1;
            else
                rightOdd(sum) += 1;
        }
    }

    #define llu unsigned long long
    llu answer = 0;
    for (int i = -n; i < n; i++)
    {
        llu a = rightEven(i);
        llu b = leftOdd(i);
        llu c = rightOdd(i);
        llu d = leftEven(i);
        answer += (a * b) + (c * d);
    }

    printf("%llu", answer);
    return 0;
}