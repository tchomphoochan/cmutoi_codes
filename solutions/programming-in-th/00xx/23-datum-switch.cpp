#include <stdio.h>

int main(){
    int d,m;
    int valM1 = 4; int valM2 = 0; int valM3 = 0;
    int valM4 = 3; int valM5 = 5; int valM6 = 1;
    int valM7 = 3; int valM8 = 6; int valM9 = 2;
    int valM10 = 4; int valM11 = 0; int valM12 = 2;
    scanf("%d%d",&d,&m);
    int valC;
    switch(m){
        case 1: valC = (valM1 + d -1)%7; break;
        case 2: valC = (valM2 + d -1)%7; break;
        case 3: valC = (valM3 + d -1)%7; break;
        case 4: valC = (valM4 + d -1)%7; break;
        case 5: valC = (valM5 + d -1)%7; break;
        case 6: valC = (valM6 + d -1)%7; break;
        case 7: valC = (valM7 + d -1)%7; break;
        case 8: valC = (valM8 + d -1)%7; break;
        case 9: valC = (valM9 + d -1)%7; break;
        case 10: valC = (valM10 + d -1)%7; break;
        case 11: valC = (valM11 + d -1)%7; break;
        case 12: valC = (valM12 + d -1)%7; break;
    }
    switch(valC){
        case 0: printf("Sunday"); break;
        case 1: printf("Monday"); break;
        case 2: printf("Tuesday"); break;
        case 3: printf("Wednesday"); break;
        case 4: printf("Thursday"); break;
        case 5: printf("Friday"); break;
        case 6: printf("Saturday"); break;
    }
    return 0;
}

/*
วิธีการใช้ array มาช่วย ในการแก้ไขปัญหานี้ให้สั้นลง
int main(){
    int d,m;
    int valM[12] = {4,0,0,3,5,1,3,6,2,4,0,2};
    scanf("%d%d",&d,&m);
    int valC = (valM[m-1]+d-1)%7;
    switch(valC){
        case 0: printf("Sunday"); break;
        case 1: printf("Monday"); break;
        case 2: printf("Tuesday"); break;
        case 3: printf("Wednesday"); break;
        case 4: printf("Thursday"); break;
        case 5: printf("Friday"); break;
        case 6: printf("Saturday"); break;
    }
    return 0;
}
*/