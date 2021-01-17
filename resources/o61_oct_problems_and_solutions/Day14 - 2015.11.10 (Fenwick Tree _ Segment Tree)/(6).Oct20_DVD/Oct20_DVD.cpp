#include <cstdio>
#include <algorithm>
#define SIZE 100000
#define INF 1000000000
using namespace std;

class S{
public:
    int Min, Max;
    S(){}
};
int arr[SIZE+5];
S ST[4*SIZE+5];

void build(int idx, int L, int R){
    if(L == R){
        ST[idx].Min = arr[L];
        ST[idx].Max = arr[L];
        return;
    }
    int mid = (L+R)/2;
    build(idx*2, L, mid);
    build(idx*2+1, mid+1, R);
    ST[idx].Min = min(ST[idx*2].Min, ST[idx*2+1].Min);
    ST[idx].Max = max(ST[idx*2].Max, ST[idx*2+1].Max);
}

void update(int idx, int L, int R, int x, int v){
    if(L == R){
        ST[idx].Max = v;
        ST[idx].Min = v;
        return;
    }
    int mid = (L+R)/2;
    if(x <= mid)
        update(idx*2, L, mid, x, v);
    else
        update(idx*2+1, mid+1, R, x, v);
    ST[idx].Min = min(ST[idx*2].Min, ST[idx*2+1].Min);
    ST[idx].Max = max(ST[idx*2].Max, ST[idx*2+1].Max);
}

pair<int, int> fullDVD(int idx, int L, int R, int x, int y){
    if(R < x || y < L)
        return make_pair(INF, -INF);
    if(x <= L && R <= y){
        return make_pair(ST[idx].Min, ST[idx].Max);
    }
    int mid = (L+R)/2;
    pair<int, int> childL = fullDVD(idx*2, L, mid, x, y);
    pair<int, int> childR = fullDVD(idx*2+1, mid+1, R, x, y);
    return make_pair(min(childL.first, childR.first), max(childL.second, childR.second));
}

int main(){
    int N, Q;
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; ++i)
        arr[i] = i;
    build(1, 1, N);
    while(Q--){
        int opr, a, b;
        scanf("%d%d%d", &opr, &a, &b);
        a++;
        b++;
        if(opr == 0){
            swap(arr[a], arr[b]);
            update(1, 1, N, a, arr[a]);
            update(1, 1, N, b, arr[b]);
        }
        else if(opr == 1){
            pair<int, int> chk = fullDVD(1, 1, N, a, b);
            //printf("%d->%d = %d->%d\n", a, b, chk.first, chk.second);
            if(chk.first == a && chk.second == b)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
/*
5 8
1 0 4
1 1 2
0 1 3
1 2 2
1 1 3
1 0 0
1 0 2
1 2 4

5 5
0 1 2
0 2 3
0 1 3
1 0 1
1 0 2
*/
