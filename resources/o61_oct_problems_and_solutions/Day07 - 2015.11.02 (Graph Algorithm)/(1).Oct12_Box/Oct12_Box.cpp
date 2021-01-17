#include <cstdio>
#include <queue>
using namespace std;

class NODE{
public:
    int fiR, fiC, enR, enC;
    NODE(int fiR, int fiC, int enR, int enC){
        this->fiR = fiR;
        this->fiC = fiC;
        this->enR = enR;
        this->enC = enC;
    }
};
int R, C;
int dR[] = {-1, 0, 0, 1};
int dC[] = {0, -1, 1, 0};
bool visited[35][35];
char box[35][35];
queue<NODE> q;

bool valid(int r, int c){
    if(box[r][c] == '.' && box[r][c+1] == '.' && box[r+1][c] == '.' && box[r+1][c+1] == '.')
        return 1;
    else
        return 0;
}

bool bfs(){
    while(!q.empty()){
        int fiR = q.front().fiR, fiC = q.front().fiC, enR = q.front().enR, enC = q.front().enC;
        q.pop();
        if(enR == R-1)
            return 1;
        for(int i = 0; i < 4; ++i){
            int nfiR = fiR+dR[i], nfiC = fiC+dC[i], nenR = enR+dR[i], nenC = enC+dC[i];
            if(nfiR >= 0 && nfiR < R && nfiC >= 0 && nfiC < C &&
               nenR >= 0 && nenR < R && nenC >= 0 && nenC < C &&
               !visited[nfiR][nfiC] && valid(nfiR, nfiC)){
                visited[nfiR][nfiC] = true;
                q.push(NODE(nfiR, nfiC, nenR, nenC));
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d%d", &R, &C);
    for(int i = 0; i < R; ++i)
        scanf("%s", &box[i]);
    for(int c = 0; c < C-1; ++c){
        if(box[0][c] == '.' && box[0][c+1] == '.' && box[1][c] == '.' && box[1][c+1] == '.'){
            visited[0][c] = true;
            q.push(NODE(0, c, 1, c+1));
        }
    }
    if(bfs())
        printf("yes");
    else
        printf("no");
    return 0;
}
