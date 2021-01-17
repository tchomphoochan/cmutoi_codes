#include <cstdio>
#include <cmath>

int city[500005], N;

int PROCESS(int s){
    int sum = 0;
    for(int i = 1; i <= N; ++i)
        sum+=ceil((double)city[i]/s);
    return sum;
}

int main(){
    int want;
    scanf("%d%d", &N, &want);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &city[i]);
    int L = 1, R = 5000000, mid, idx = -1;
    while(L <= R){
        mid = (L+R)/2;
        int now = PROCESS(mid);
        //printf("%d (%d)\n", mid, now);
        if(now <= want){
            idx = mid;
            R = mid-1;
        }
        else if(now > want)
            L = mid+1;
    }
    printf("%d", idx);
    return 0;
}
/*
2 7
200
500

4 6
12
268
340
20
*/
