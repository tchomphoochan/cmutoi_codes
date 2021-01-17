#include <cstdio>

int nCr[15][15], idx = 0, L, out[15];
bool visited[15];
void NchooseR(int len, int ma, int N, int R){
    if(idx == L)
        return;
    if(len == R){
        idx++;
        /*
        printf("%d -> ", idx);
        for(int i = 0; i < K; ++i)
            printf("%d ", out[i]);
        printf("\n");
        */
        if(idx == L){
            for(int i = 0; i < R; ++i)
                printf("%d ", out[i]);
        }
        return;
    }
    else{
        for(int i = ma+1; i <= N; ++i){
            if(!visited[i]){
                out[len] = i;
                visited[i] = true;
                NchooseR(len+1, i, N, R);
                visited[i] = false;
            }
        }
    }
    return;
}


int main(){
    int N, K;
    scanf("%d%d%d", &N, &K, &L);
    for(int i = 0; i <= N; ++i)
        nCr[i][0] = nCr[i][i] = 1;
    for(int i = 2; i <= N; ++i){
        for(int j = 1; j <= K; ++j){
            nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
        }
    }
    L%=nCr[N][K];
    if(L == 0)
        L = nCr[N][K];
    NchooseR(0, 0, N, K);
    return 0;
}
