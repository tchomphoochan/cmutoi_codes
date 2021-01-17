#include <cstdio>

char inp[1005];

void rec(int len){
    if(inp[len] == NULL)
        return;
    rec(len+1);
    printf("%c", inp[len]);
}

int main(){
    scanf("%s", &inp);
    rec(0);
    return 0;
}
