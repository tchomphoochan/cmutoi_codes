#include <cstdio>
#include <algorithm>

#define N 1010

int main()
{
    int n;
    scanf("%d", &n);
    int arr[N];
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    
    int skip = 0;
    for (int i = 1; i <= n; ++i) {
        if (i&1) { // left

            int s = (i+1)/2;
            if (arr[s] == s) {
                ++skip;
                continue;
            }

            for (int j = s+1; j <= n; ++j) {
                if (arr[j] == s) {
                    while (j > s) {
                        std::swap(arr[j], arr[j-1]);
                        --j;
                    }
                    break;
                }
            }

        } else { // right

            int s = n - i/2 + 1;
            if (arr[s] == s) {
                ++skip;
                continue;
            }

            for (int j = s-1; j >= 0; --j) {
                if (arr[j] == s) {
                    while (j < s) {
                        std::swap(arr[j], arr[j+1]);
                        ++j;
                    }
                    break;
                }
            }

        }
    }

    printf("%d", skip);

    return 0;
}