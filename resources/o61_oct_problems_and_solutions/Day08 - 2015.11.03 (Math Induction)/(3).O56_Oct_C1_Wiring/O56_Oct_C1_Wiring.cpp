#include <cstdio>

int H[100005], up[100005], down[100005];
int findH(int a){
    if(H[a] == a)
        return a;
    return H[a] = findH(H[a]);
}

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        int N;
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i){
            scanf("%d", &up[i]);
            H[i] = i;
        }
        for(int i = 1; i <= N; ++i)
            scanf("%d", &down[i]);
        bool can = true;
        for(int i = 1; i <= N; ++i){
            if(up[i] == 0 || down[i] == 0 || up[i] == down[i])
                continue;
            int hUp = findH(up[i]), hDown = findH(down[i]);
            if(hUp != hDown)
                H[hDown] = hUp;
            else if(hUp == hDown){
                //printf("U%d D%d HU%d HD%d\n", up[i], down[i], hUp, hDown);
                can = false;
                break;
            }
        }
        if(can)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
/*
#include <cstdio>
#include <cstring>

int markUp[100005], markDown[100005];
int up[100005], downHah[100005];

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        memset(markUp, 0, sizeof(markUp));
        memset(markDown, 0, sizeof(markDown));
        int N;
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i)
            scanf("%d", &up[i]);
        for(int i = 1; i <= N; ++i){
            int x;
            scanf("%d", &x);
            if(up[i] == x && up[i] != 0 && x != 0)
                markUp[i] = markDown[i] = i;
            downHah[x] = i;
        }
        bool can = true;
        for(int i = 1; i <= N; ++i){
            if(!markUp[i] && up[i] != 0){

                int posD = downHah[up[i]];
                //printf("%d & %d (%d)\n", i, posD, up[i]);
                if((markDown[i] != 0 && (markDown[i] >= posD || markUp[posD] != 0))){
                    can = false;
                    break;
                }
                markUp[i] = posD;
                markDown[posD] = i;
            }
        }
        if(can)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
*/
/*
3
5
2 3 1 4 0
1 3 0 4 2
3
1 2 3
2 3 1
5
1 0 0 0 2
2 0 0 0 1
*/
