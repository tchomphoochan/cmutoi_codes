#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int D = 200;
const int A = 26;

int n;
char s[N];

int main()
{
    scanf("%s", s);
    n = strlen(s);

    int ans = n;
    for (int p = 2; p <= n; ++p) {
        if (n%p != 0) continue;
        int l = n/p;

        int tt = 0;

        for (int i = 0; i < l; ++i) {
            int cnt[A] = {};
            int mx = 0;
            for (int j = 0; j < p; ++j) {
                char c = s[j*l+i]-'a';
                mx = max(mx, ++cnt[c]);
            }
            tt += p-mx;
        }

        ans = min(ans, tt);
    }

    printf("%d\n", ans);

    return 0;
}