#include <cstdio>

char inp[1005];
void rec2(int len, int ma){
    if(len == ma){
        return;
    }
    printf("%c", inp[len]);
    rec2(len+1, ma);
}
void rec(int st, int len){
    if(inp[len] == NULL){
        rec2(st, len);
        return;
    }
    else if(inp[len] == '_'){
        rec(len+1, len+1);
        printf("_");
        rec2(st, len);
        return;
    }
    rec(st, len+1);
}

int main(){
    scanf("%s", inp);
    rec(0, 0);
    return 0;
}
