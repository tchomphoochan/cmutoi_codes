#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    char x = 'A';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%c", x);
            if (x == 'Z')
                x = 'A';
            else
                ++x;
        }
        printf("\n");
    }
}