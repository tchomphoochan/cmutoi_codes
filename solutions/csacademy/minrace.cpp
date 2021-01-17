#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5+10;

pii cars[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int c, r;
        scanf("%d%d", &c, &r);
        cars[i] = {r, c};
    }
    sort(cars, cars+n);
    
    multiset<int> lis;
    for (int i = 0; i < n; ++i) {
        int c = cars[i].second;
        if (lis.empty() || c <= *lis.begin()) {
            lis.insert(c);
        } else {
            auto ptr = lis.lower_bound(c);
            --ptr;
            lis.erase(ptr);
            lis.insert(c);
        }
    }
    printf("%lu\n", lis.size());

    return 0;
}
