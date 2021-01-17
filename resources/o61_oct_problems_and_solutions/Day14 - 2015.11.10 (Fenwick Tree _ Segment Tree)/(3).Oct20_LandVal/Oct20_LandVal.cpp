#include <cstdio>

int FT[200005], N;

void update(int idx, int val){
    while(idx <= N){
        FT[idx]+=val;
        idx+=(idx&(-idx));
    }
}
int sumTo(int idx){
    int sum = 0;
    while(idx >= 1){
        sum+=FT[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}

int main(){
    int Q;
    scanf("%d%d", &N, &Q);
    while(Q--){
        int opr, x, y, v;
        scanf("%d", &opr);
        if(opr == 1){
            scanf("%d%d%d", &x, &y, &v);
            update(x, v);
            update(y+1, -v);
        }
        else if(opr == 2){
            scanf("%d", &x);
            printf("%d\n", sumTo(x));
        }
    }
    return 0;
}

