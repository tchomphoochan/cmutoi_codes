#include <cstdio>

int N, FT[1050][1050];

void update(int x, int y, int val){
    int tmpy = y;
    while(x <= N){
        y = tmpy;
        while(y <= N){
            FT[x][y]+=val;
            y+=(y&(-y));
        }
        x+=(x&(-x));
    }
}
int sumTo(int x, int y){
    int sum = 0, tmpy = y;
    while(x >= 1){
        y = tmpy;
        while(y >= 1){
            sum+=FT[x][y];
            y-=(y&(-y));
        }
        x-=(x&(-x));
    }
    return sum;
}

int main(){
    int opr, x1, y1, x2, y2, v;
    scanf("%d%d", &opr, &N);
    while(scanf("%d", &opr) && opr != 3){
        if(opr == 1){
            scanf("%d%d%d", &x1, &y1, &v);
            x1++;
            y1++;
            update(x1, y1, v);
        }
        else if(opr == 2){
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1++;
            y1++;
            x2++;
            y2++;
            printf("%d\n", sumTo(x2, y2) - sumTo(x1-1, y2) - sumTo(x2, y1-1) + sumTo(x1-1, y1-1));
        }
    }
    return 0;
}
/*
0 4
1 1 2 3
2 0 0 2 2
1 1 1 2
1 1 2 -1
2 1 1 2 3
3
*/
