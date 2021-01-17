#include <stdio.h>

int n;
int arr[1000000];

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (i % 2 == 0)
            arr[i] = -arr[i];
    }

    if (n == 1)
    {
        printf("%d", arr[0] > 0 ? -arr[0] : arr[0]);
        return 0;
    }

    int maxStart = 0;
    int maxEnd = 0;
    int maxSum = 0;

    int curStart = 0;
    int curEnd = 0;
    int curSum = 0;

    while (curEnd < n)
    {
        curSum += arr[curEnd];
        if (curSum > maxSum)
        {
            maxStart = curStart;
            maxEnd = curEnd;
            maxSum = curSum;
        }
        if (curSum <= 0)
        {
            curStart = curEnd + 1;
            curSum = 0;
        }

        curEnd++;
    }

    int diff = 0;
    for (int i = 0; i < n; i++)
        diff += (i >= maxStart && i <= maxEnd) ? -arr[i] : arr[i];
    
    printf("%d", diff);
}
