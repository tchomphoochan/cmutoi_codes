#include <cstdio>

int idx = 0, L, out[15];
bool visited[15];
void nPr(int len, int N, int K){
    if(idx == L)
        return;
    if(len == K){
        idx++;
    /*
        printf("%d -> ", idx);
        for(int i = 0; i < K; ++i)
            printf("%d ", out[i]);
        printf("\n");
        //*/
        if(idx == L){
            for(int i = 0; i < K; ++i)
                printf("%d ", out[i]);
        }
        return;
    }
    else{
        for(int i = 1; i <= N && idx < L; ++i){
            if(!visited[i]){
                out[len] = i;
                visited[i] = true;
                nPr(len+1, N, K);
                visited[i] = false;
            }
        }
    }
    return;
}


int main(){
    int N, K, round = 1;
    scanf("%d%d%d", &N, &K, &L);
    for(int i = N-K+1; i <= N; ++i)
        round*=i;
    L%=round;
    if(L == 0)
        L = round;
    //L = round;
    //printf("%d\n", L);
    nPr(0, N, K);
    return 0;
}
