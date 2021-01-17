#include <cstdio>
#include <cmath>

using namespace std;

const int N = 210;

char s[N];

int main()
{
    scanf("%s", s);
    int cnt = 0;
    int ans = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(')
            ++cnt;
        else
            --cnt;
        if (cnt < 0) {
            cnt = 0;
            ++ans;
        }
    }

    ans += cnt;
    printf("%d", ans);
    return 0;
}