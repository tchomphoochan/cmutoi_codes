#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    
    set<int> border;
    for (int i = 0; i < m; i++)
    {
        int x, r;
        scanf("%d %d", &x, &r);
        int y = x + r;

        pair<set<int>::iterator, bool> xi = border.insert(x);
        if (!xi.second)
            border.erase(xi.first);
           
        pair<set<int>::iterator, bool> yi = border.insert(y);
        if (!yi.second)
            border.erase(yi.first);
    }
    border.insert(n + 1);

    for (int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);

        set<int>::iterator low = border.upper_bound(x);
        set<int>::iterator high = low--;
        printf("%d\n", *high - (high == border.begin() ? 1 : *low));
    }
}

/*
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

int comp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    ios::sync_with_stdio(false);

    int n, m, q;
  //  cin >> n >> m >> q;
    scanf("%d %d %d",&n,&m,&q);
    int c = 0;
    int temp[200000];
    for (int i = 0; i < m; i++) {
        int x, r;
       // cin >> x >> r;
        scanf("%d %d",&x,&r);
        int y = x + r;

        temp[c++] = x;
        temp[c++] = y;
    }
    temp[c++] = n + 1;
    qsort(temp, c, sizeof(int), comp);
    //sort(temp, temp + c);

    int d = 0;
    int border[200000];
    for (int i = 0; i < c; i++) {
        if (d > 0 && border[d - 1] == temp[i])
            d--;
        else
            border[d++] = temp[i];
    }
    //for(int i=0; i<d; ++i)printf("%d ",border[i]);
    //printf("\n");
    for (int i = 0; i < q; i++) {
        int x;
        //cin >> x;
        scanf("%d",&x);

        int *low = upper_bound(border, border + d, x);
        int *high = low--;
     //   cout << *high - (high == border ? 1 : *low) << endl;
        printf("%d\n",*high - (high == border ? 1 : *low) );
    }
}
*/