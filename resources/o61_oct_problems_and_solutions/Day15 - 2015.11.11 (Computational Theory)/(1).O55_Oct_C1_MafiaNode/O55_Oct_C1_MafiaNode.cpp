#include <cstdio>
#define SIZE 1000000

class NODE{
public:
    int ma, num;
    NODE(){}
};
NODE ST[4*SIZE+5];
bool mafia[SIZE+5];

void chkChild(int idx){
    if(ST[idx*2].ma == ST[idx*2+1].ma){
        if(ST[idx*2].num > ST[idx*2+1].num)
            ST[idx] = ST[idx*2];
        else
            ST[idx] = ST[idx*2+1];
    }
    else if(ST[idx*2].ma > ST[idx*2+1].ma)
        ST[idx] = ST[idx*2];
    else
            ST[idx] = ST[idx*2+1];
}

void build(int idx, int L, int R){
    if(L == R){
        ST[idx].ma = 0;
        ST[idx].num = L;
        return;
    }
    int mid = (L+R)/2;
    build(idx*2, L, mid);
    build(idx*2+1, mid+1, R);
    chkChild(idx);
}
void update(int idx, int L, int R, int x, int v){
    if(L == R){
        ST[idx].ma+=v;
        return;
    }
    int mid = (L+R)/2;
    if(x <= mid)
        update(idx*2, L, mid, x, v);
    else
        update(idx*2+1, mid+1, R, x, v);
    chkChild(idx);
}

int main(){
    char opr[4];
    int N, L, R, Q, x, y;
    scanf("%d%d%d", &N, &L, &R);
    build(1, 1, N);
    Q = L+R;
    while(Q--){
        scanf("%s", opr);
        if(opr[0] == 'L'){
            scanf("%d%d", &x, &y);
            if(mafia[x] || mafia[y])
                continue;
            update(1, 1, N, y, 1);
        }
        else if(opr[0] == 'C'){
            scanf("%d%d", &x, &y);
            if(mafia[x] || mafia[y])
                continue;
            update(1, 1, N, y, 3);
        }
        else if(opr[0] == 'R'){
            printf("%d\n", ST[1].num);
        }
        else if(opr[0] == 'D'){
            NODE delNode = ST[1];
            update(1, 1, N, delNode.num, -(delNode.ma+1000000));
            mafia[delNode.num] = true;
        }
    }
    return 0;
}
/*
5 9 4
L 2 1
L 3 1
L 1 4
R
L 5 3
D
R
C 2 3
C 4 3
L 5 3
L 5 4
L 2 4
R
*/
