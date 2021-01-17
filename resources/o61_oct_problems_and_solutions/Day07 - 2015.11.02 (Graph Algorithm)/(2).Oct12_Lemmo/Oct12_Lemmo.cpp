#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
// 0-Left 1-Right

class NODE{
public:
    int r, c, di;
    NODE(int r, int c, int di){
        this->r = r;
        this->c = c;
        this->di = di;
    }
};
queue<NODE> q;
int R, C, lemmo[125][125][2];
bool canTreasure[125][125][2], visited[125][125][2], visited2[125][125];
char field[125][125];

bool rec(int r, int c, int di){
    if(visited[r][c][di])
        return canTreasure[r][c][di];
    visited[r][c][di] = true;
    //printf("%d %d %d %c\n", r, c, di, field[r][c]);
    if(field[r][c] == '.')
        return canTreasure[r][c][di] = rec(r+1, c, di);
    else if(field[r][c] == '#'){
        if(di == 0){
            if(c == 0)
                return canTreasure[r][c][di] = rec(r, c, 1);
            else
                return canTreasure[r][c][di] = rec(r, c-1, di);
        }
        else if(di == 1){
            if(c == C-1)
                return canTreasure[r][c][di] = rec(r, c, 0);
            else
                return canTreasure[r][c][di] = rec(r, c+1, di);
        }
    }
    else if(field[r][c] == '@')
        return canTreasure[r][c][di] = 0;
    else if(field[r][c] == '$')
        return canTreasure[r][c][di] = 1;
}
void bfs(int stR, int stC, int stDi){
    q.push(NODE(stR, stC, stDi));
    while(!q.empty()){
        int r = q.front().r, c = q.front().c, di = q.front().di;
        q.pop();
        //printf("%d %d %d %c\n", r, c, di, field[r][c]);
        if(!visited2[r][c])
            lemmo[r][c][di]++;
        visited2[r][c] = true;
        if(field[r][c] == '.')
            q.push(NODE(r+1, c, di));
        else if(field[r][c] == '#'){
            if(di == 0){
                if(c == 0)
                    q.push(NODE(r, c, 1));
                else
                    q.push(NODE(r, c-1, di));
            }
            else if(di == 1){
                if(c == C-1)
                    q.push(NODE(r, c, 0));
                else
                    q.push(NODE(r, c+1, di));
            }
        }
        else if(field[r][c] == '@')
            continue;
        else if(field[r][c] == '$')
            continue;
    }
}
void DEBUG(){
    printf("\n---LEFT---\n");
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j)
            printf("%d ", canTreasure[i][j][0]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j)
            printf("%2d ", lemmo[i][j][0]);
        printf("\n");
    }
    printf("---RIGHT---\n");
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j)
            printf("%d ", canTreasure[i][j][1]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j)
            printf("%2d ", lemmo[i][j][1]);
        printf("\n");
    }
    printf("\n");
}

int main(){
    scanf("%d%d", &C, &R);
    for(int i = 0; i < R; ++i){
        scanf("%s", field[i]);
    }
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            rec(i, j, 0);
            rec(i, j, 1);
        }
    }
    for(int j = 0; j < C; ++j){
        memset(visited2, 0, sizeof(visited2));
        bfs(0, j, 0);
        memset(visited2, 0, sizeof(visited2));
        bfs(0, j, 1);
    }
    //DEBUG();
    int cnt = 0;
    for(int j = 0; j < C; ++j)
        cnt+=canTreasure[0][j][0]+canTreasure[0][j][1];
    int ma = cnt;
    for(int i = 0; i < R-1; ++i){
        for(int j = 0; j < C; ++j){
            int plus = 0;
            if(canTreasure[i][j][0] == 0 && canTreasure[i+1][j][0] == 1)
                plus+=lemmo[i][j][0];
            else if(canTreasure[i][j][0] == 1 && canTreasure[i+1][j][0] == 0)
                plus-=lemmo[i][j][0];
            if(canTreasure[i][j][1] == 0 && canTreasure[i+1][j][1] == 1)
                plus+=lemmo[i][j][1];
            else if(canTreasure[i][j][1] == 1 && canTreasure[i+1][j][1] == 0)
                plus-=lemmo[i][j][1];
            ma = max(ma, cnt+plus);
        }
    }
    printf("%d %d", cnt, ma);
    return 0;
}
/*
12 4
#####.###.##
###.#####.##
#.####.#####
@##$########

12 4
#####.###.##
###.#####.##
#.####.##.##
@##$#####@##
*/
