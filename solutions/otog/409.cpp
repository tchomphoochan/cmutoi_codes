#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            bool print = true;
            for (int k = 0; k < 10; ++k) {
                int x = (i/(2<<k))%2;
                int y = (j/(2<<k))%2;
                if (x == 1 && y == 1)
                    print = false;
            }

            int x = i%4;
            int y = j%4;

            if (print && (x == 0 || y == 0 || (x == 3-y)))
                printf("#");
            else
                printf(".");

        }
        printf("\n");
    }

    return 0;
}