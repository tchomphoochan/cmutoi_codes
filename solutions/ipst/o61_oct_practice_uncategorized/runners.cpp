#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

double spd[N], waste[N], done[N];
int ix[N];

int main()
{
    int q;
    scanf("%d", &q);
    while (q--) {

        int n;
        double len;
        scanf("%d%lf", &n, &len);
        
        for (int i = 0; i < n; ++i) {
            ix[i] = i;
            scanf("%lf%lf", &spd[i], &waste[i]);
            done[i] = waste[i] + 1000*len/spd[i];
        }
        auto cmp = [&] (int a, int b) {
            return (done[a] < done[b] || (done[a] == done[b] && spd[a] > spd[b]));
        };
        sort(ix, ix+n, cmp);
        for (int i = 0; i < n; ++i)
            printf("%d\n", ix[i]+1);

    }
    return 0;
}