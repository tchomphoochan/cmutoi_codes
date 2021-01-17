#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--) {

        char s[N];
        int cnt[26] = {};
        scanf(" %s", s);
        
        for (int i = 0; s[i]; ++i)
            ++cnt[tolower(s[i])-'a'];
        sort(cnt, cnt+26, greater<int>());
        int ans = 0;
        for (int i = 0; i < 26; ++i)
            ans += cnt[i]*(26-i);
        printf("%d\n", ans);

    }

    return 0;
}