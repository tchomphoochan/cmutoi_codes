#include <bits/stdc++.h>

using namespace std;

const int N = 15;
int a[N], b[N];

int main()
{
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;
        int m;
        scanf("%d", &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < m; ++i)
            scanf("%d", &b[i]);
        vector<double> rt;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                rt.push_back(a[i]*1.0/b[j]);
        }
        sort(rt.begin(), rt.end());
        double mx = 0;
        for (int i = 0; i < rt.size()-1; ++i) {
            mx = max(mx, rt[i+1]/rt[i]);
        }
        printf("%.2f\n", mx);
    }

    return 0;
}