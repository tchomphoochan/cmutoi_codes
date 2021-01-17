#include <stdio.h>

int main(){
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    char day[7][20] = {"Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday"};
    int d,m;
    scanf("%d%d",&d,&m);
    int totalday = 0;
    int stmonth = 0;
    while(stmonth < m - 1){
        totalday += month[stmonth];
        ++stmonth;
    }
    totalday += (d - 1);
    int date = totalday%7;
    printf("%s",day[date]);
}