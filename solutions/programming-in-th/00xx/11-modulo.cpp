#include <stdio.h>

int arr[42];

int main()
{
    int cnt = 0;
    for (int i = 0; i < 10; ++i) {
        int x;
        scanf("%d", &x);
        x %= 42;
        if (arr[x] == 0)
            ++cnt;
        arr[x] = 1;
    }
    printf("%d\n", cnt);
    return 0;
}