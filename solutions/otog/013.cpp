#include <cstdio>

#define T 1000002

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[T] = {};
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            ++arr[x]; --arr[y];
        }
        int sum = 0;
        bool ans = true;
        for (int i = 1; i < T; ++i) {
            sum += arr[i];
            if (sum >= n) {
                ans = false;
                break;
            }
        }

        printf("%s\n", ans ? "yes" : "no");
    }

    return 0;
}