#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<char> ans[27];
char P[1005], E[2005];

int main(){
    scanf("%s%s", &P, &E);
    int lenP = strlen(P), lenE = strlen(E);
    int J = 0, ansIDX = 0;
    for(int i = 0; i < lenP; ++i){
        //printf("%d and %d\n", i, J);
        if(P[i] != E[J] && P[i] >= 'A' && P[i] <= 'Z'){
            int bracket = 0;
            if(E[J] == '(' && i+1 < lenP){
                ans[ansIDX].push_back(E[J]);
                bracket++;
                J++;
                while(bracket && J < lenE){
                    //printf("J: %d\n", J);
                    ans[ansIDX].push_back(E[J]);
                    if(E[J] == ')')
                        bracket--;
                    else if(E[J] == '(')
                        bracket++;
                    J++;
                }
                ansIDX++;
            }
            else if(E[J] == '(' && i+1 >= lenP){
                printf("no");
                return 0;
            }
            else{
                while(J < lenE && E[J] != P[i+1] && E[J] != ','){
                    ans[ansIDX].push_back(E[J]);
                    J++;
                }
                ansIDX++;
            }
            if(J >= lenE || E[J] != P[i+1]){
                printf("no");
                return 0;
            }
            J--;
        }
        else if(P[i] != E[J]){
            printf("no");
            return 0;
        }
        J++;
    }
    for(int i = 0; i < ansIDX; ++i){
        for(int j = 0; j < ans[i].size(); ++j)
            printf("%c", ans[i][j]);
        printf("\n");
    }
    return 0;
}
