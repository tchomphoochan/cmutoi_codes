#include <cstdio>

#define N 100010

int n;
char s[N];

int main()
{
    scanf("%d %s", &n, s+1);

    char f = 'X';
    for (int i = 1; i <= n; ++i) {
        if (s[i] != 'X') {
            if (i % 2 == 0)
                f = s[i] == 'B' ? 'W' : 'B';
            else
                f = s[i];
            break;
        }
    }

    s[1] = f;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != 'X')
            continue;    
        if (s[i-1] != 'B' && s[i+1] != 'B')
            s[i] = 'B';
        else if (s[i-1] != 'W' && s[i+1] != 'W')
            s[i] = 'W';
        else
            s[i] = 'G';
    }

    printf("%s", s+1);

    return 0;
}