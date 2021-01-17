#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int arr[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    int cut = 0;
    for (int i = n-2; i >= 0; --i) {
        if (arr[i] < arr[i+1]) {
            cut = i;
            break;
        }
    }

    int big = 0;
    for (int i = n-1; i > cut; --i) {
        if (arr[i] > arr[cut]) {
            big = i;
            break;
        }
    }

    for (int i = 0; i < cut; ++i)
        printf("%d\n", arr[i]);
    printf("%d\n", arr[big]);
    for (int i = n-1; i > big; --i)
        printf("%d\n", arr[i]);
    printf("%d\n", arr[cut]);
    for (int i = big-1; i > cut; --i)
        printf("%d\n", arr[i]);

    return 0;
}