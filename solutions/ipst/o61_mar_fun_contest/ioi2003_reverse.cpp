#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main()
{
    int k, n;
    scanf("%d%d", &k, &n);
    printf("FILE reverse %d\n", k);
    for (int x = 0; x < n; ++x) {
        if (n-7*x-8 <= x) {
            for (int i = 1; i <= 9; ++i) {
                arr[i] = (i-1)*(x+1);
                printf("%d", arr[i]);
                if (i != 9) printf(" ");
                else printf("\n");
            }
            int at = n;
            while (at >= 0) {
                // 9 case
                if (at > arr[9]) {
                    printf("S 9 9\n");
                    ++arr[9];
                    continue;
                }
                if (at == arr[9]) {
                    printf("P 9\n");
                    --at;
                    continue;
                }
                // 1-8 case
                for (int i = 8; i >= 0; --i) {
                    if (at == arr[i]) {
                        printf("P %d\n", i);
                        --at;
                        break;
                    } else if (at > arr[i]) {
                        printf("S %d %d\n", i, i+1);
                        arr[i+1] = arr[i]+1;
                        break;
                    }
                }
            }
            break;
        }
    }

    return 0;
}