/**
 * toi11_cannon
 * 
 * aquablitz11 (2017)
 */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

#define N 1000010
#define M 1010

int pos[N];

int main()
{
    int n, m, k, l;
    scanf("%d%d%d%d", &n, &m, &k, &l);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &pos[i]);
    }

    while (k--) {

        vector<ii> q;
        q.reserve(m*2);
        for (int i = 0; i < m; ++i) {
            int x;
            scanf("%d", &x);
            q.push_back({x-l, 1});
            q.push_back({x+l+1, -1});
        }
        sort(q.begin(), q.end(), [&] (ii a, ii b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });

        int start = 0;
        int sum = 0;
        int cnt = 0;
        for (auto d : q) {
            sum += d.second;
            if (sum == 0) {
                int right = upper_bound(pos, pos+n, d.first-1) - pos;
                int left = lower_bound(pos, pos+n, start) - pos;
                cnt += right - left;
            }
            if (sum-d.second == 0 && sum == 1) {
                start = d.first;
            }
        }

        printf("%d\n", cnt);

    }

    return 0;
}