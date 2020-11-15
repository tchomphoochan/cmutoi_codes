/**
 * Code Jam 2020 Qualification Round
 * B. Nesting Depth
 *
 * aquablitz11 (2020-04-04)
 * Greedy parenthesis nesting
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        char str[10010];
        scanf("%s", str);
        int n = strlen(str);
        int cnt = 0;
        printf("Case #%d: ", t);
        for (int i = 0; i < n; ++i) {
            while (cnt < str[i]-'0') {
                ++cnt;
                printf("(");
            }
            while (cnt > str[i]-'0') {
                --cnt;
                printf(")");
            }
            printf("%c", str[i]);
        }
        while (cnt > 0) {
            --cnt;
            printf(")");
        }
        printf("\n");
    }
    
    return 0;
}