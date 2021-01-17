#include <cstdio>
#include <algorithm>
using namespace std;

int H[100005], increasing[100005], diff[100005];

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; ++i)
        scanf("%d", &H[i]);
    for(int i = N-2; i >= 0; --i){
        if(H[i] <= H[i+1])
            increasing[i] = increasing[i+1]+1;
    }
    int ma = 0;
    for(int i = 0; i < N-1; ++i){
        diff[i] = H[i+1]-H[i];
        ma = max(ma, diff[i]);
        //printf("%d ", increasing[i]);
    }
    for(int i = 0; i < M; ++i){
        int x, cnt = 0;
        scanf("%d", &x);
        if(x >= ma){
            printf("0\n");
            continue;
        }
        for(int i = 0; i < N-1; ++i){
            int tmp = H[i];
            if(H[i+1]-tmp > x){
                while(i+1 < N && H[i+1] > tmp && H[i+1]-tmp > x){
                    cnt++;
                    i++;
                }
                i--;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
/*
5 5
1
3
4
2
3

1
2
3
4
5

9 5
7
3
6
10
11
5
123
123
45

1
2
3
4
5
*/
