#include <cstdio>

int main(){
    int oddPow, evenPow, P, even = 0, odd = 0;
    bool finish = false;
    scanf("%d", &P);
    oddPow = evenPow = P;
    P*=2;
    while(P--){
        int x;
        scanf("%d", &x);
        if(finish)
            continue;
        if(x%2 == 0){   //even
            odd = 0;
            even++;
            if(even >= 3)
                oddPow-=3;
            else
                oddPow--;
            if(oddPow <= 0){
                printf("0\n%d", x);
                finish = true;
            }
        }
        else{
            even = 0;
            odd++;
            if(odd >= 3)
                evenPow-=3;
            else
                evenPow--;
            if(evenPow <= 0){
                printf("1\n%d", x);
                finish = true;
            }
        }
    }
    return 0;
}
