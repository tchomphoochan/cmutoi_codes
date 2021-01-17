#include <cstdio>
/// 0-N || 1-E || 2-S || 3-W
char inp[105];
char diHah[] = {'N', 'E', 'S', 'W'};

int main(){
    scanf("%s", inp);
    int di = 0;
    for(int i = 0; inp[i] != NULL; ++i){
        if(inp[i] == 'Z'){
            printf("Z");
            di = 0;
            continue;
        }
        while(diHah[di] != inp[i]){
            printf("R");
            di = (di+1)%4;
        }
        printf("F");
    }
    return 0;
}
