#include <stdio.h>

int n;
int arr[2500];

int main(void)
{
    scanf("%d", &n);

    int maxStart = 0;
    int maxEnd = 0;
    int maxSum = 0;

    int nowStart = 0;
    int nowSum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        nowSum += arr[i];
        if (nowSum > maxSum) {
            maxStart = nowStart;
            maxEnd = i;
            maxSum = nowSum;
        } else if (nowSum < 0) {
            nowSum = 0;
            nowStart = i+1;
        }
    }

    if (maxSum <= 0) {
        printf("Empty sequence");
    } else {
        for (int i = maxStart; i <= maxEnd; ++i)
            printf(" %d", arr[i]);
        printf("\n%d", maxSum);
    }

    return 0;
}