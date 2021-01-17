#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

class NODE{
public:
    int r, c, w;
    NODE(int r, int c, int w){
        this->r = r;
        this->c = c;
        this->w = w;
    }
};
int dR[] = {-1, 0, 0, 1};
int dC[] = {0, -1, 1, 0};
queue<NODE> q;
bool canWalk[155][155], BOMB[155][155];
int R, C, walk[155][155], bomb = 0, mi = 1000000000;
void bfs(int type, int stR, int stC){
    q.push(NODE(stR, stC, 1));
    walk[stR][stC] = 1;
    while(!q.empty()){
        int r = q.front().r, c = q.front().c, w = q.front().w;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nR = r+dR[i], nC = c+dC[i];
            if(type == 2){
                if(nR >= 1 && nR <= R && nC >= 1 && nC <= C && !canWalk[nR][nC] && walk[nR][nC] != 0 && !BOMB[nR][nC]){
                    bomb++;
                    BOMB[nR][nC] = true;
                    mi = min(mi, walk[nR][nC]+w);
                }
                else if(nR >= 1 && nR <= R && nC >= 1 && nC <= C && canWalk[nR][nC] && walk[nR][nC] == 0){
                    walk[nR][nC] = w+1;
                    q.push(NODE(nR, nC, w+1));
                }
            }
            else if(type == 1){
                if(nR >= 1 && nR <= R && nC >= 1 && nC <= C && !canWalk[nR][nC] && walk[nR][nC] == 0){
                    walk[nR][nC] = w+1;
                }
                else if(nR >= 1 && nR <= R && nC >= 1 && nC <= C && canWalk[nR][nC] && walk[nR][nC] == 0){
                    walk[nR][nC] = w+1;
                    q.push(NODE(nR, nC, w+1));
                }
            }
        }
    }
}

int main(){
    int stR, stC, exR, exC;
    scanf("%d%d", &R, &C);
    scanf("%d%d", &stR, &stC);
    scanf("%d%d", &exR, &exC);
    for(int i = 1; i <= R; ++i)
        for(int j = 1; j <= C; ++j)
            scanf("%d", &canWalk[i][j]);
    bfs(1, stR, stC);
    bfs(2, exR, exC);
    printf("%d\n%d", bomb, mi);
    return 0;
}
