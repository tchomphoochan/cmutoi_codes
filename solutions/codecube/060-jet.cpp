#include <cstdio>
#include <algorithm>

#define N 100010

int kadane(int arr[], int n, int &maxstart, int &maxend)
{
    maxstart = 0;
    maxend = 0;
    int maxsum = 0;

    int start = 1;
    int sum = 0;
    int maxix = 1;
    for (int i = 1; i <= n; ++i) {
        if (arr[i] > arr[maxix])
            maxix = i;
        sum += arr[i];
        if (sum > maxsum
        || (sum == maxsum && i - start < maxend - maxstart)
        || (sum == maxsum && i - start == maxend - maxstart && start < maxstart)) {
            maxsum = sum;
            maxstart = start;
            maxend = i;
        }
        if (sum <= 0) {
            sum = 0;
            start = i+1;
        }
    }

    if (arr[maxix] < 0) {
        maxstart = maxend = maxix;
        return arr[maxix];
    }

    return maxsum;
}

int main()
{
    int n;
    scanf("%d", &n);
    char way[N];
    int cute[N];
    int ls = 0, rs = 0;

    for (int i = 1; i <= n; ++i) {
        scanf(" %c%d", &way[i], &cute[i]);
        if (way[i] == 'L')
            ls += cute[i];
        else
            rs += cute[i];
    }
    
    // right
    int arr[N], arr2[N];
    for (int i = 1; i <= n; ++i) {
        arr[i] = way[i] == 'L' ? cute[i] : -cute[i];
        arr2[i] = -arr[i];
    }
    int maxstart, maxend, maxstart2, maxend2;
    int maxsum = rs + kadane(arr, n, maxstart, maxend);
    int maxsum2 = ls + kadane(arr2, n, maxstart2, maxend2);

    if (maxsum >= maxsum2)
        printf("R %d %d %d", maxsum, maxstart, maxend);
    else
        printf("L %d %d %d", maxsum2, maxstart2, maxend2);

    return 0;
}