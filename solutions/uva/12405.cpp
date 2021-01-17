#include <bits/stdc++.h>

using namespace std;

const int N = 110;

char s[N];

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d %s", &n, s);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '.') {
                ++cnt;
                s[i] = s[i+1] = s[i+2] = '#';
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}