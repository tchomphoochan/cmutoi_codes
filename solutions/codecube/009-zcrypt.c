#include <stdio.h>

int main(void)
{
    int k, n;
    char ciph[1001] = {};
    char plain[1001] = {};
    scanf("%d ", &k);
    gets(ciph);
    n = strlen(ciph);

    if (k == 1) {
        printf("%s", ciph);
        return 0;
    }

    int i = 0, j = k-1;
    while (j < n) {
        for (int m = 0; m < k && j+m < n; ++m)
            plain[j+m] = ciph[i++];
        j += 4 * (k-1);
    }
    for (j = 1; j < k-1; ++j) {
        int col = k-j-1;
        bool up = true;
        while (col < n) {
            plain[col] = ciph[i++];
            col += k + 2 * (up ? j-1 : k-j-2) + 1;
            up = !up;
        }
    }
    plain[0] = ciph[i++];
    j = 3 * (k-1);
    while (j < n) {
        for (int m = 0; m < k && j+m < n; ++m)
            plain[j+m] = ciph[i++];
        j += 4 * (k-1);
    }

    printf("%s", plain);
    return 0;
}