#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int cs = sqrt(c)+2;
        bool found = false;
        for (int x = -cs; x <= cs; ++x) {
            for (int y = -cs; y <= cs; ++y) {
                for (int z = -cs; z <= cs; ++z) {
                    if (x+y+z == a
                    && x*y*z == b
                    && x*x + y*y + z*z == c) {
                        found = true;
                        printf("%d %d %d\n", x, y, z);
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (found)
                break;
        }
        if (!found)
            printf("No solution.\n");
    }

    return 0;
}