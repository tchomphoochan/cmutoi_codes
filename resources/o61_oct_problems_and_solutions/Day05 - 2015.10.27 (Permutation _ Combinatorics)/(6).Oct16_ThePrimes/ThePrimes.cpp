#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
        //First-Digit End-Digit Sum-Digit
class DIGITS{
public:
    int val, digit[6], sumDig;
    DIGITS(){}
};
int sumEach, square[6][6];
vector<DIGITS> Prime[10][50], PrimeNoZero[10][50];
bool chk[100005];

pair<DIGITS, bool> sumDigit(int x){
    int sum = 0, i = 4;
    DIGITS tmp;
    tmp.val = x;
    bool haveZero = false;
    while(x > 0){
        tmp.digit[i--] = x%10;
        if(x%10 == 0)
            haveZero = true;
        sum+=x%10;
        x/=10;
    }
    tmp.sumDig = sum;
    return make_pair(tmp, haveZero);
}
void printSquare(){
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            printf("%d", square[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool valid(){
    int sum = 0, mul = 10000, sumD = 0;
    for(int j = 2; j <= 4; ++j){
        sum = 0, sumD = 0;
        mul = 10000;
        for(int i = 0; i <= 4; ++i){
            sumD+=square[i][j];
            sum+=(square[i][j]*mul);
            //printf("(%d,%d)\n", i, j);
            mul/=10;
        }

        if(sumD != sumEach || chk[sum])
            return false;
    }
    sum = 0, sumD = 0, mul = 10000;
    for(int i = 0; i <= 4; ++i){
        sum+=square[i][i]*mul;
        sumD+=square[i][i];
        mul/=10;
    }
    if(sumD != sumEach || chk[sum])
        return false;
    sum = 0, sumD = 0, mul = 10000;
    for(int i = 0; i <= 4; ++i){
        sum+=square[4-i][i]*mul;
        sumD+=square[4-i][i];
        mul/=10;
    }
    if(sumD != sumEach || chk[sum])
        return false;
    return true;
}
/*
11351
14033
30323
53201
13313
*/
void rec(int row){
    if(row == 5){
        //printSquare();
        /*
        if(square[0][0] == 1 && square[0][1] == 1 && square[0][2] == 3 && square[0][3] == 5 && square[0][4] == 1 &&
           square[1][0] == 1 && square[2][0] == 3 && square[3][0] == 5 && square[4][0] == 1 &&
           square[4][1] == 3 && square[4][2] == 3 && square[4][3] == 1 && square[4][4] == 3 && square[3][1] == 3 &&
           square[2][1] == 0 && square[2][2] == 3 ){
           printSquare();
           printf("Valid %d\n", valid());
        }
        */
        if(valid())
            printSquare();
        return;
    }
    else{
        for(int l = 0; l < Prime[square[row][0]][sumEach].size(); ++l){
            if(Prime[square[row][0]][sumEach][l].digit[1] == square[row][1]){
                for(int i = 4; i >= 0; --i){
                    square[row][i] = Prime[square[row][0]][sumEach][l].digit[i];
                    //printf("(%d,%d) %d %d\n", row, i, Prime[square[row][0]][sumEach][l].val, Prime[square[row][0]][sumEach][l].digit[i]);
                }
                rec(row+1);
            }
        }
    }
}


int main(){
    for(int i = 2; i < 100000; i++){
        if(!chk[i]){
            if(i >= 10000){
                pair<DIGITS, bool> sum = sumDigit(i);
                Prime[i/10000][sum.first.sumDig].push_back(sum.first);
                if(!sum.second)
                    PrimeNoZero[i/10000][sum.first.sumDig].push_back(sum.first);
            }
            for(int j = i+i; j <= 100000; j+=i)
                chk[j] = true;
        }
    }
    int ma = 0;
    /*
    for(int i = 1; i <= 9; ++i){
        for(int l = 1; l <= 9; ++l){
            for(int j = 0; j < 50; ++j){
                ma = max(ma, (int)Prime[i][l][j].size());
            }
        }
    }
    */
    int upLeft;
    scanf("%d%d", &sumEach, &upLeft);
    for(int k1 = 0; k1 < PrimeNoZero[upLeft][sumEach].size(); ++k1)
    {
        //printf("--%d--\n", PrimeNoZero[upLeft][sumEach][k1].val);
        for(int i1 = 4; i1 >= 0; --i1)
            square[0][i1] = PrimeNoZero[upLeft][sumEach][k1].digit[i1];
            //printf("%d", PrimeNoZero[upLeft][sumEach][k1].digit[i]);
        //printf("\n");
        for(int k2 = 0; k2 < PrimeNoZero[upLeft][sumEach].size(); ++k2)
        {
            for(int i2 = 4; i2 >= 0; --i2)
                square[i2][0] = PrimeNoZero[upLeft][sumEach][k2].digit[i2];
            for(int k3 = 0; k3 < Prime[square[0][1]][sumEach].size(); ++k3)
            {
                for(int i3 = 4; i3 >= 1; --i3)
                    square[i3][1] = Prime[square[0][1]][sumEach][k3].digit[i3];
                //printSquare();
                rec(1);
            }
        }
    }
    return 0;
}
