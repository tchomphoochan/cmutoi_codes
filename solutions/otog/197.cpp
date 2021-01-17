#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
char s[N];

int main()
{
    scanf("%s", s);
    for (int i = 0; s[i]; ++i) {
        if (islower(s[i]))
            printf("%c", toupper(s[i]));
        else
            printf("%c", tolower(s[i]));
    }

    return 0;
}