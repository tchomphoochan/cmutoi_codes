#include <stdio.h>

int main(){
   int n;
   scanf("%d",&n);
   //กรณีเลขคู่
   if(n%2 == 0){
       int mid = n/2;
       int a = mid, b = mid;
       for(int i = 1;i<=n;++i){
           for(int j = 1;j<=n-1;++j){
               if(j == a || j == b) printf("*");
               else printf("-");
           }
           printf("\n");
           if(i < mid){
               a--; b++;
           }
           else if(i > mid) {
               a++; b--;
           }
       }
   }
   //กรณีเลขคี่
   if(n%2 != 0){
       int mid = (n/2)+1;
       int a = mid, b = mid;
       for(int i = 1;i<=n;++i){
           for(int j = 1;j<=n;++j){
               if(j == a || j == b) printf("*");
               else printf("-");
           }
           printf("\n");
           if(i < mid){
               a--; b++;
           }
           else {
               a++; b--;
           }
       }
   }
}