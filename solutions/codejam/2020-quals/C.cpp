/**
 * Code Jam 2020 Qualification Round
 * C. Parenting Partnering Returns
 *
 * aquablitz11 (2020-04-04)
 * Greedy scheduling
 */

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using piipi = pair<pii, int>;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        int n;
        scanf("%d", &n);
        vector<piipi> v;
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            v.push_back({{x, y}, i});
        }
        sort(v.begin(), v.end());

        char ans[10010] = {};
        int tim1 = 0, tim2 = 0;
        for (auto x : v) {
            if (x.first.first >= tim1) {
                ans[x.second] = 'C';
                tim1 = x.first.second;
            } else if (x.first.first >= tim2) {
                ans[x.second] = 'J';
                tim2 = x.first.second;
            } else {
                strcpy(ans, "IMPOSSIBLE");
                break;
            }
        }

        printf("%s", ans);
        printf("\n");
    }
    
    return 0;
}