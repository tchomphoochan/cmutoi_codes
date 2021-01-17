#include <cstdio>
#include <cstring>

int len, K;
char inp[105];
int abs(int a){
    return a<0? -a:a;
}

int main(){
    scanf("%s", inp);
    scanf("%d", &K);
    int N = 0, S = 0, E = 0, W = 0;
    for(int i = 0; inp[i] != NULL; ++i){
        if(inp[i] == 'N')
            N++;
        else if(inp[i] == 'S')
            S++;
        else if(inp[i] == 'E')
            E++;
        else if(inp[i] == 'W')
            W++;
    }
    int ma = 0, mi = 0;
    if(N > S){
        ma+=N;
        mi+=S;
    }
    else{
        ma+=S;
        mi+=N;
    }
    if(E > W){
        ma+=E;
        mi+=W;
    }
    else{
        ma+=W;
        mi+=E;
    }
    mi-=K;
    if(mi < 0){
        ma = ma - abs(mi);
        mi = 0;
    }
    printf("%d", (ma-mi)*2);
    return 0;
}
