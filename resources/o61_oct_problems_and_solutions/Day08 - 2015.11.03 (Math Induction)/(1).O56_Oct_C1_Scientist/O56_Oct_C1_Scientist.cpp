#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

class MACHINE{
public:
    int loss[5], get[5];
    MACHINE(){}
};
MACHINE M[10];
int wantChicken, wantDog, wantCat;
class PETS{
public:
    int a, b, c, w;
    PETS(int a, int b, int c, int w){
        this->a = a;
        this->b = b;
        this->c = c;
        this->w = w;
    }
};
queue<PETS> q;
int path[25][25][25];
bool bfs(){
    while(!q.empty()){
        int pet[] = {0, q.front().a, q.front().b, q.front().c};
        int w = q.front().w;
        q.pop();
        //printf("Chick:%d Dog:%d Cat:%d %d Path: %d\n", pet[1], pet[2], pet[3], w, path[pet[1]][pet[2]][pet[3]]);
        //system("pause");
        if(pet[1] == wantChicken && pet[2] == wantDog && pet[3] == wantCat){
            printf("%d ", w);
            return true;
        }
        int next[5];
        for(int i = 1; i <= 6; ++i){
            bool can = true;
            for(int j = 1; j <= 3; ++j){
                next[j] = pet[j]-M[i].loss[j];
                if(next[j] < 0){
                    can = false;
                    break;
                }
            }
            if(!can)
                continue;
            //
            //printf("MACHINE %d\n", i);
            for(int j = 1; j <= 3; ++j){
                next[j]+=M[i].get[j];
                if(next[j] > 20){
                    can = false;
                    break;
                }
            }
            if(can && path[next[1]][next[2]][next[3]] == 0){
                path[next[1]][next[2]][next[3]] = i;
                q.push(PETS(next[1], next[2], next[3], w+1));
            }
        }
    }
    return false;
}

char ans[10005];

int main(){
    M[1].loss[1] = 1;
    M[2].loss[2] = 1;
    M[3].loss[3] = 1;
    M[4].get[1] = 1;
    M[5].get[2] = 1;
    M[6].get[3] = 1;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; ++j){
            scanf("%d", &M[i].get[j]);
            M[i+3].loss[j] = M[i].get[j];
        }
    }
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        int a, b, c;
        while(!q.empty())
            q.pop();
        memset(path, 0, sizeof(path));
        scanf("%d%d%d", &a, &b, &c);
        path[a][b][c] = -1;
        q.push(PETS(a, b, c, 0));
        scanf("%d%d%d", &wantChicken, &wantDog, &wantCat);
        if(bfs()){
            int trav = path[wantChicken][wantDog][wantCat], idx = 0;
            int n[5] = {0, wantChicken, wantDog, wantCat};
            while(trav != -1){
                int now = path[n[1]][n[2]][n[3]];
                if(now == 1)
                    ans[idx++] = 'A';
                else if(now == 2)
                    ans[idx++] = 'B';
                else if(now == 3)
                    ans[idx++] = 'C';
                else if(now == 4)
                    ans[idx++] = 'a';
                else if(now == 5)
                    ans[idx++] = 'b';
                else if(now == 6)
                    ans[idx++] = 'c';
                for(int i = 1; i <= 3; ++i)
                    n[i] = n[i] - M[now].get[i] + M[now].loss[i];
                trav = path[n[1]][n[2]][n[3]];
            }
            for(int i = idx-1; i >= 0; --i)
                printf("%c", ans[i]);
            printf("\n");
        }
        else
            printf("NO SOLUTION\n");
    }
    return 0;
}
/*
0 1 0
1 1 1
1 1 0
2
0 1 1 3 0 0
1 0 0 2 0 0
*/
