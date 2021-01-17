#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

bool dead[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    int alive = n, cnt = 0;
    for (int i = 1; alive; ++i) {
        if (i == n+1)
            i = 1;
        if (dead[i])
            continue;
        if (++cnt == k) {
            dead[i] = true;
            --alive;
            printf("%d ", i);
            cnt = 0;
        }
    }

    return 0;
}