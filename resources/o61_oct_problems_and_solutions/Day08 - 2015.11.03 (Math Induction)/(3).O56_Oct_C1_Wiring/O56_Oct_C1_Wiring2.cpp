#include <cstdio>
#include <cstring>

int up[100005], lowerThan[100005];
bool visited[100005];

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        memset(lowerThan, 0, sizeof(lowerThan));
        memset(visited, 0, sizeof(visited));
        int N;
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i)
            scanf("%d", &up[i]);
        for(int i = 1; i <= N; ++i){
            int x;
            scanf("%d", &x);
            if(up[i] != x && up[i] != 0 && x != 0)
                lowerThan[up[i]] = x;
        }
        bool can = true;
        for(int i = 1; i <= N; ++i){
            if(lowerThan[up[i]] == 0 || up[i] == 0)
                continue;
            if(!visited[up[i]]){
                int trav = up[i];
                while(!visited[trav] && lowerThan[trav] != up[i] && trav != 0){
                    //printf("%d\n", trav);
                    visited[trav] = true;
                    trav = lowerThan[trav];
                }
                //printf("LOWER %d IS %d\n", up[i], lowerThan[trav]);
                if(lowerThan[trav] == up[i] && trav != 0){
                    can = false;
                    break;
                }
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
