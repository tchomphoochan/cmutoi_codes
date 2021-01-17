#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<int> a(n), b(m);
    double as = 0, bs = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        as += a[i];
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
        bs += b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (as/n < bs/m) {
        swap(n, m);
        swap(a, b);
        swap(as, bs);
    }

    int cnt = 0;
    auto it = upper_bound(a.begin(), a.end(), bs/m);
    while (as/n > bs/m) {
        if (*it >= as/n)
            break;
        as -= *it; --n;
        bs += *it; ++m;
        ++cnt; ++it;
    }
    printf("%d", cnt);

    return 0;
}