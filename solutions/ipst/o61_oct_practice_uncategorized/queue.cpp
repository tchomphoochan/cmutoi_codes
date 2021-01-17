#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const int N = 100010;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef pair<int, int> pii;
int prio[N];

int main()
{
    ordered_set<pii> s;

    int m, c, p, i = 0;
    scanf("%d", &m);
    while (m--) {

        scanf("%d", &c);
        if (c == 1) {
            scanf("%d", &p);
            prio[++i] = p;
            s.insert({p, i});
        } else if (c == 2) {
            int ans = 0;
            if (!s.empty()) {
                ans = s.begin()->second;
                s.erase(s.begin());
            }
            printf("%d\n", ans);
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", s.order_of_key({prio[x], x}));
        }

    }

    return 0;
}