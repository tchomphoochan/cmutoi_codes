#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 130;

int n, m;
char s[N], t[N], k[N];

void change(char &a, char &b, char &c)
{
    char x[] = {a, b, c};
    sort(x, x+3);
    b = x[1];
}

int main()
{
    scanf("%d%d %s %s %s", &n, &m, s, t, k);
    for (int a = -m+1; a < n; ++a) {
        for (int i = 0; i < m; ++i) {
            if (a+i < 0 || a+i >= n)
                continue;
            change(s[a+i], k[i], t[a+i]);
        }
    }

    printf("%s", k);
    return 0;
}