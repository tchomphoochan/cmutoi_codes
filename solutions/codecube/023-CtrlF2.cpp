#include <cstdio>

const int N = 1000010;

char s[N], p[N];
int lps[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf(" %s %s", s, p);

    int i, j;
    for (i = 1; i < m; ++i) {
        if (p[i] == p[lps[i-1]]) {
            lps[i] = lps[i-1]+1;
        } else {
            lps[i] = p[i] == p[0] ? 1 : 0;
        }
    }

    int cnt = 0;
    i = 0;
    j = 0;
    while (i < n) {
        if (s[i] == p[j]) {
            ++i;
            ++j;
            if (j == m) {
                ++cnt;
                j = lps[j-1];
            }
        } else if (j == 0) {
            ++i;
        } else {
            j = lps[j-1];
        }
    }

    printf("%d", cnt);
    return 0;
}