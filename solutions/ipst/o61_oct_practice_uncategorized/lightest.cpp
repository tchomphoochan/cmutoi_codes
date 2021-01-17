#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (int i = 0; i < n+m; ++i) {
        char q;
        scanf(" %c", &q);
        if (q == 'T') {
            int w, v;
            scanf("%d%d", &w, &v);
            pq.push({w, v});
        } else {
            if (!pq.size()) {
                printf("0\n");
            } else {
                pii d = pq.top();
                pq.pop();
                printf("%d\n", d.second);
            }
        }
    }

    return 0;
}