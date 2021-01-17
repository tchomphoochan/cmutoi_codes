#include <cstdio>
#include <cstring>
#include <queue>
#define INF 1000000000
using namespace std;

class NODE{
public:
    int r, c, t;
    NODE(){}
    NODE(int r, int c, int t){
        this->r = r;
        this->c = c;
        this->t = t;
    }
};
int ghost[105][105], R, C, T;
bool visited[105][105][1005];
int dR[] = {-1, 0, 0, 1, 0};
int dC[] = {0, -1, 1, 0, 0};
NODE inp[105];
char field[105][105];
queue<NODE> q;
void bfs(){
    while(!q.empty()){
        int r = q.front().r, c = q.front().c, t = q.front().t;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nR = r+dR[i], nC = c+dC[i];
            if(nR >= 0 && nR < R && nC >= 0 && nC < C && field[nR][nC] == '.' && t+1 < ghost[nR][nC]){
                ghost[nR][nC] = t+1;
                q.push(NODE(nR, nC, t+1));
            }
        }
    }
}
bool bfs2(){
    while(!q.empty()){
        int r = q.front().r, c = q.front().c, t = q.front().t;
        q.pop();
        if(t >= ghost[r][c])
            continue;
        if(t == T)
            return true;
        for(int i = 0; i < 5; ++i){
            int nR = r+dR[i], nC = c+dC[i];
            if(nR >= 0 && nR < R && nC >= 0 && nC < C && !visited[nR][nC][t+1] && t+1 < ghost[nR][nC] && field[nR][nC] == '.'){
                visited[nR][nC][t+1] = true;
                q.push(NODE(nR, nC, t+1));
            }
        }
    }
    return false;
}

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        int n, sR, sC;
        scanf("%d%d%d%d%d%d", &R, &C, &n, &T, &sR, &sC);
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                ghost[i][j] = INF;
            }
        }
        for(int i = 0; i < n; ++i){
            int t, r, c;
            scanf("%d%d%d", &t, &r, &c);
            inp[i] = NODE(r, c, t);
        }
        for(int i = 0; i < R; ++i)
            scanf("%s", field[i]);
        for(int i = 0; i < n; ++i){
            int r = inp[i].r, c = inp[i].c, t = inp[i].t;
            if(field[r][c] == '.' && t < ghost[r][c]){
                ghost[r][c] = t;
                q.push(NODE(r, c, t));
                bfs();
            }
        }
        /*
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                printf("%d ", ghost[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */
        memset(visited, 0, sizeof(visited));
        q.push(NODE(sR, sC, 0));
        visited[sR][sC][0] = true;
        if(bfs2()){
            printf("YES\n");
        }
        else
            printf("NO\n");

    }
    return 0;
}
/*
3
2 5 1 1 0 2
0 0 2
.....
.....
2 5 1 1 0 2
1 0 2
.....
.....
2 5 4 1 0 2
1 0 2
1 0 3
1 0 1
1 1 2
.....
.....

2
5 5 2 10 2 2
0 0 0
0 4 4
.....
.###.
.#.#.
.###.
.....
5 5 2 4 2 2
0 0 0
0 4 4
.....
.###.
...#.
.###.
.....
*/
