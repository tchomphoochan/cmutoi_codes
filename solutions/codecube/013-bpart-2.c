#include <stdio.h>

int n, k;
int arr[1000] = {};

bool isPossible(int s)
{
    int c = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sum + arr[i] > s) {
            ++c;
            sum = arr[i];
        }
        else {
            sum += arr[i];
        }
    }
    return c < k;
}


int main(void)
{
    scanf("%d%d", &n, &k);
    int sum = 0;
    int max = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max;
    int high = sum;
    while (low < high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    printf("%d", low);
    return 0;
}