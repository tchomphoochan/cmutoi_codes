#include <cstdio>
#include <cstring>

#define L 1010

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        char s[L];
        scanf(" %s", s);
        int l = strlen(s);
        if ((l == 1 && s[0] == '2')
        || (s[l-1]-'0')%2 != 0)
            printf("T\n");
        else
            printf("F\n");
    }
    return 0;
}