#include <stdio.h>
int sum[4];
int main(){
    int x;
    for(int i = 0;i<5;++i){
        for(int j = 0;j<4;++j){
            scanf("%d",&x);
            sum[i]+=x;
        }
    }
    int maxIndex, maxValue = -1;
    for(int i = 0;i<5;++i){
        if(sum[i] > maxValue){
            maxValue = sum[i];
            maxIndex = i+1;
        }
    }
    printf("%d %d",maxIndex,maxValue);
    return 0;
}