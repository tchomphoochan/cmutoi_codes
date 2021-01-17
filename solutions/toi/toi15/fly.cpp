/**
 * toi15_fly
 * 
 * aquablitz11 (2020)
 * 75/100
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, m;
int A[N], B[N];
inline int get_x0(int x, char d) {
    if (d == 'R')
        return x;
    else
        return 2*m-x;
}
inline int get_pos(int x, int t) {
    int y = (x+t)%(2*m);
    if (y < m)
        return y;
    else
        return 2*m-y;
}
inline bool ok(int r, int c, int t) {
    if (r == 0 || r == n+1)
        return true;
    int L = get_pos(A[r], t);
    int R = get_pos(B[r], t);
    if (L > R) swap(L, R);
    if (c <= L || c >= R)
        return false;
    return true;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int a, c;
        char b, d;
        scanf("%d %c%d %c", &a, &b, &c, &d);
        A[i] = get_x0(a, b);
        B[i] = get_x0(c, d);
    }
    vector<int> cho;
    for (int c = 1; c <= m-1; ++c)
        cho.push_back(c);
    mt19937 RNG(31415926);
    shuffle(cho.begin(), cho.end(), RNG);
    int mnt = 1e9;
    for (auto c : cho) {
        bool R[N+2] = {};
        R[0] = true;
        int t;
        //printf("c = %d\n", c);
        for (t = 1; t < mnt; ++t) {
            bool NR[N+2] = {};
            for (int r = 0; r < n+1; ++r) {
                if (R[r] && ok(r, c, t))
                    NR[r] = true;
                if (R[r] && ok(r+1, c, t))
                    NR[r+1] = true;
            }
            if (t > 2*m)
                NR[0] = false;
            int cnt = 0;
            for (int r = 0; r <= n+1; ++r) {
                R[r] = NR[r];
                //printf("%c", R[r]?'T':'F');
                if (R[r])
                    ++cnt;
            }
            //printf("\n");
            if (cnt == 0 || R[n+1])
                break;
        }
        //printf("\n");
        if (R[n+1])
            mnt = min(mnt, t);
    }
    printf("%d\n", mnt);
    
    return 0;
}