#include <bits/stdc++.h>

using namespace std;

const int K = 1010;

int pos[K][2];

int main()
{
    int n, k, d;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &d);
        pos[i][0] = d;
        pos[i][1] = (n-d)%n;
    }
    int p2 = pos[1][0];
    for (int i = 0; i < k; ++i) {
        scanf("%d", &d);
        int n1 = (p2+d)%n;
        int n2 = (p2-d+n)%n;
        if (n1 == pos[i][0])
            pos[i][0] = n1;
        else if (n2 == pos[i][0])
            pos[i][0] = n2;
        else if (n1 == pos[i][1])
            pos[i][0] = n1;
        else
            pos[i][0] = n2;
    }

    for (int i = 0; i < k; ++i)
        printf("%d\n", pos[i][0]);

    return 0;
}