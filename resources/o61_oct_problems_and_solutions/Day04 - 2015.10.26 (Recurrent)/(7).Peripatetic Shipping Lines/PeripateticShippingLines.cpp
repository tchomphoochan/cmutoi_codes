#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

char sch[105][100005];
vector<int> daySch[105];
int PAIR[105], DAY[105];
queue<int> q;

int main(){
    int N, M, totalCase;
    scanf("%d", &totalCase);
    for(int T = 1; T <= totalCase; ++T){
        scanf("%d%d", &N, &M);
        for(int i = 0; i <= N; ++i){
             DAY[i] = PAIR[i] = 0;
             daySch[i].clear();
             daySch[i].push_back(0);
        }
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                scanf("%d", &sch[i][j]);
                if(sch[i][j] != 0)
                    daySch[i].push_back(j);
            }
            q.push(i);
        }
        /*
        for(int i = 1; i <= N; ++i){
            for(int j =1; j <= N; ++j)
                printf("%d ", daySch[i][j]);
            printf("\n");
        }
        */
        while(!q.empty()){
            int ship = q.front(), pt;
            //printf("Q: %d\n", ship);
            q.pop();
            bool loop = true;
            while(loop){
                loop = false;
                DAY[ship]++;
                pt = sch[ship][daySch[ship][DAY[ship]]];
                int oldPt = PAIR[pt];
                if(oldPt != 0){
                    if(daySch[oldPt][DAY[oldPt]] < daySch[ship][DAY[ship]])
                        q.push(oldPt);
                    else
                        loop = true;
                }
            }
            PAIR[pt] = ship;
        }
        /*
        for(int d = 1; d <= M; ++d){
            bool yes = true;
            while(yes){
                yes = false;
                for(int i = 1; i <= N; ++i){
                    if(sch[i][d] && DAY[i] == 0){
                        int old = PAIR[sch[i][d]];
                        DAY[old] = 0;
                        PAIR[sch[i][d]] = i;
                        DAY[i] = d;
                        yes = true;
                    }
                }
            }
            for(int i = 1; i <= N; ++i)
                printf("%d ", PAIR[i]);
            printf("\n");
        }
        */
        printf("TEST %d\n", T);
        for(int i = 1; i <= N; ++i)
            printf("%d\n", daySch[i][DAY[i]]);
    }
    return 0;
}
/*
2
2 4
1 0 2 0
0 1 0 2
3 7
1 0 2 0 3 0 0
2 0 1 0 0 3 0
0 1 0 0 2 0 3
*/
