#include <cstdio>

bool visited[1005];
int N, arr[1005], out[1005], cnt = -1;
int loop(int i, int N){
    if(i > N){
        return 0;
    }
    if(!visited[i])
        return i;
    else
        return loop(i+1, N);
}
void printArrOut(int i){
    if(i >= N)
        return;
    printf("%d\n", out[i]);
    printArrOut(i+1);
}
void nextPermutation(int len){
    if(cnt == 1)
        return;
    if(len == N){
        cnt++;
        /*
        printf("CNT: %d\n", cnt);
        for(int i = 0; i < N; ++i)
            printf("%d ", out[i]);
        printf("\n");
        //*/
        if(cnt == 1)
            printArrOut(0);
        return;
    }
    else{
        int now;
        if(cnt == 0){
            now = loop(1, N);
            out[len] = now;
            visited[now] = true;
            nextPermutation(len+1);
            return;
        }
        else if(cnt == -1){
            out[len] = arr[len];
            visited[arr[len]] = true;
            nextPermutation(len+1);
        }
        now = loop(out[len]+1, N);
        visited[out[len]] = false;
        //printf("%d L:%d(%d) N:%d\n", cnt, len+1, arr[len], now);
        if(now != 0){
            out[len] = now;
            visited[now] = true;
            nextPermutation(len+1);
        }
    }
}
bool decreaseScan(int i){
    if(i >= N)
        return 1;
    scanf("%d", &arr[i]);
    if(i == 0)
        return decreaseScan(i+1);
    else
        return (decreaseScan(i+1))&(arr[i-1] > arr[i]);
}
void printInOrder(int i){
    if(i > N)
        return;
    printf("%d\n", i);
    printInOrder(i+1);
}

int main(){
    scanf("%d", &N);
    bool decrease = decreaseScan(0);
    if(decrease)
        printInOrder(1);
    else
        nextPermutation(0);
    return 0;
}
/*
5
1
3
2
5
4
*/
