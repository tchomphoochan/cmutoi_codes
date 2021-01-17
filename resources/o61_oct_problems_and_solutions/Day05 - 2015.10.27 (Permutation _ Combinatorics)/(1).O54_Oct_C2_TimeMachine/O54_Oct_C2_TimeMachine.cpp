#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class timeMachine{
public:
    int r, c, p;
    timeMachine(int r, int c, int p){
        this->r = r;
        this->c = c;
        this->p = p;
    }
};
bool visited[15];
int out[15], R, C, mi, K, dist[15][15];
vector<timeMachine> tM;
void rec(int last, int sum){
    //printf("%d %d\n", last, sum);
    if(last == K){
        mi = min(mi, sum);
        return;
    }
    else{
        for(int i = 1; i <= K; ++i){
            if(!visited[i]){
                visited[i] = true;
                rec(i, sum+dist[last][i]);
                visited[i] = false;
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &R, &C, &K);
    tM.push_back(timeMachine(0, 0, 0));
    for(int i = 1; i <= K; ++i){
        int x, y, p;
        scanf("%d%d%d", &x, &y, &p);
        tM.push_back(timeMachine(x, y, p));
    }
    tM.push_back(timeMachine(R-1, C-1, 0));
    K++;
    for(int i = 0; i <= K; ++i){
        for(int j = 0; j <= K; ++j){
            int diffR = tM[i].r-tM[j].r, diffC = tM[i].c-tM[j].c;
            dist[i][j] = ceil(sqrt(diffR*diffR + diffC*diffC))-tM[j].p;
        }
    }
    mi = dist[0][K];
    rec(0, 0);
    printf("%d", mi);
    return 0;
}
