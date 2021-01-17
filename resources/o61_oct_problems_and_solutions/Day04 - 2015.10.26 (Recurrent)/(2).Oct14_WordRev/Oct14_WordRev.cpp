#include <cstdio>

char inp[1005];
void rec2(int st, int len){
    if(len == st-1){
        return;
    }
    printf("%c", inp[len]);
    rec2(st, len-1);
}
void rec(int st, int len){
    if(inp[len] == NULL){
        rec2(st, len-1);
        return;
    }
    else if(inp[len] == '_'){
        rec2(st, len-1);
        printf("_");
        rec(len+1, len+1);
        return;
    }
    rec(st, len+1);
}

int main(){
    scanf("%s", &inp);
    rec(0, 0);
    return 0;
}
