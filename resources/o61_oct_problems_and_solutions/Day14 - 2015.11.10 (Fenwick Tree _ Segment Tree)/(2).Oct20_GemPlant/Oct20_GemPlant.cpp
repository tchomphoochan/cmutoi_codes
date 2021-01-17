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
        int opr, x, y;
        scanf("%d%d%d", &opr, &x, &y);
        if(opr == 1)
            update(y, x);
        else if(opr == 2)
            printf("%d\n", sumTo(y)-sumTo(x-1));
    }
    return 0;
}
