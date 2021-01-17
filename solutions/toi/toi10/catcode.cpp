/**
 * toi10_catcode
 * 
 * aquablitz11 (2017)
 * 100/100
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define K 100010
#define M 35
#define N 110
#define D 1000010

int main()
{
    unordered_multimap<int, int> keys;

    int k, m;
    scanf("%d%d", &k, &m);
    for (int i = 1; i <= k; ++i) {
        char p[M];
        scanf(" %s", p);
        int hv = 0;
        for (int j = 0; j < m; ++j) {
            hv <<= 1;
            hv |= p[j]-'0';
        }
        keys.insert({hv, i});
    }

    int n;
    scanf("%d", &n);
    while (n--) {
        int d;
        char s[D];
        scanf("%d %s", &d, s);
        int cnt = 0;
        int hv = 0;
        for (int i = 0; i < m-1; ++i) {
            hv <<= 1;
            hv |= s[i]-'0';
        }
        vector<int> ans;
        for (int i = m-1; i < d; ++i) {
            hv <<= 1;
            hv |= s[i]-'0';
            hv &= (1<<m)-1;
            auto pit = keys.equal_range(hv);
            for (auto it = pit.first; it != pit.second; ++it) {
                ans.push_back(it->second);
            }
        }
        if (ans.empty()) {
            printf("OK");
        } else {
            sort(ans.begin(), ans.end());
            auto end = unique(ans.begin(), ans.end());
            printf("%d", ans[0]);
            for (auto it = ans.begin()+1; it != end; ++it)
                printf(" %d", *it);
        }
        printf("\n");
    }

    return 0;
}
