#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char s[N];

void loopb(int i, int to, int inc, function<bool(int)> act)
{
    if (i == to) return;
    if (!act(i)) return;
    loopb(i+inc, to, inc, act);
}
void loop(int i, int to, int inc, function<void(int)> act)
{
    if (i == to) return;
    act(i);
    loop(i+inc, to, inc, act);
}

int main()
{
    scanf("%s", s);
    int n = strlen(s);

    char *t = strtok(s, "_");
    loopb(0, -1, 1, [&] (int i) {

        int m = strlen(t);
        if (i != 0) printf("_");
        loop(m-1, -1, -1, [&] (int j) {
            printf("%c", t[j]);
        });

        t = strtok(NULL, "_");
        return t;
    });

    return 0;
}