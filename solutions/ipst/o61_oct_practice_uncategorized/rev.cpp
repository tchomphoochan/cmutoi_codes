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

    loop(n-1, -1, -1, [&] (int i) {
        printf("%c", s[i]);
    });

    return 0;
}