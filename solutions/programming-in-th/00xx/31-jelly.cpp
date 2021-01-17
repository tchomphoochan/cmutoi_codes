#include <stdio.h>

int main(){
   int a[3];
   for(int i = 0;i<3;++i){
       scanf("%d",&a[i]);
   }
   int cnt = 0;
   for(int i = 0;i<3;++i){
       while(a[i] != 1){
           ++cnt;
           a[i] /= 2;
       }
   }
   printf("%d",cnt);
}