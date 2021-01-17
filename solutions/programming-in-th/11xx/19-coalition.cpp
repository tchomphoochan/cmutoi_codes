#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

#define GROUP 300000 
#define TOTAL 1000000

int n;
int oldM[GROUP+1];
int M[GROUP+1];
int qs[GROUP+1] = {};
int ans[TOTAL+1] = {};
int req = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &M[i]);
        req += M[i];
    }
    req = (req / 2) + 1;
    copy(M+1, M+n+1, oldM+1);
    sort(M+1, M+n+1, greater<int>());
    for (int i = 1; i <= n; ++i)
        qs[i] = qs[i-1] + M[i];
    
    for (int i = 1; i <= n; ++i) {
        if (ans[M[i]] > 0)
            continue;
        if (qs[i] == req) {
            ans[M[i]] = i - 1;
        }
        else if (qs[i] > req) {
            int up = (upper_bound(qs+1, qs+n+1, req-M[i]) - qs);
            if (qs[up-1] == req-M[i])
                --up;
            ans[M[i]] = up;
        }
        else {
            int up = (upper_bound(qs+1, qs+n+1, req) - qs);
            if (qs[up-1] == req)
                --up;
            ans[M[i]] = up - 1;
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[oldM[i]]);

    return 0;
}