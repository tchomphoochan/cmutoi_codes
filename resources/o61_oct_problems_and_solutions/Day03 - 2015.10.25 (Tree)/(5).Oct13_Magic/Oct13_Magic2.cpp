#include <cstdio>
#include <queue>
#include <map>
using namespace std;

class HAT{
public:
    int type, time, w, v, x;
    HAT(){}
    HAT(int type, int time, int w, int v){
        this->type = type;
        this->time = time;
        this->w = w;
        this->v = v;
    }
    HAT(int type, int time, int w, int v, int x){
        this->type = type;
        this->time = time;
        this->w = w;
        this->v = v;
        this->x =x;
    }
};

map<int, HAT> hah;
map<int, vector<int> > change;
void changeType3(int i){
    map<int, vector<int> >::iterator findC = change.find(i);
    if(findC != change.end()){
        for(int j = 0; j < findC->second.size(); ++j){
            int C = findC->second[j];
            map<int, HAT>::iterator findHahC = hah.find(C);
            if(findHahC != hah.end()){
                if(findHahC->second.type == 3){
                    HAT tmp = findHahC->second;
                    hah.erase(findHahC);
                    tmp.time = 10000000;
                    tmp.type = 1;
                    tmp.w = tmp.x;
                    //printf("(%d)CHANGE: %d->%d\n", i, C, tmp.x);
                    hah[tmp.x] = tmp;
                }
            }
        }
        change.erase(findC);
    }
    return;
}

int main(){
    int N, M, opr, type, w, v, t, x;
    scanf("%d%d", &N, &M);
    N+=M;
    for(int i = 1; i <= N; ++i){
        scanf("%d", &opr);
        if(opr == 1){
            scanf("%d", &type);
            if(type == 1){
                scanf("%d%d", &w, &v);
                hah[w] = HAT(1, 10000000, w, v);
                //q.push(HAT(1, 10000000, w, v));
            }
            else if(type == 2){
                scanf("%d%d", &w, &v);
                scanf("%d", &t);
                hah[w] = HAT(2, t, w, v);
                //q.push(HAT(2, t, w, v));
            }
            else if(type == 3){
                scanf("%d%d", &w, &v);
                scanf("%d%d", &t, &x);
                if(t > i){
                    hah[w] = HAT(3, t, w, v, x);
                    change[t].push_back(w);
                }
                else if(t == i)
                    hah[x] = HAT(1, 10000000, w, v);
                //q.push(HAT(3, t, w, v, x));
            }
        }
        else if(opr == 2){
            /*
            for(map<int, HAT>::iterator it2 = hah.begin(); it2 != hah.end(); ++it2)
                printf("(%d, %d T%d) ", it2->second.w, it2->second.v, it2->second.time);
            printf("\n");
            */
            map<int, HAT>::iterator it = hah.begin();
            while(!hah.empty() && it->second.time < i){
                //printf("ERASE: %d,%d\n", it->second.w, it->second.v);
                if(it->second.type == 2)
                    hah.erase(it);
                it = hah.begin();
            }
            if(!hah.empty()){
                printf("%d\n", it->second.v);
                hah.erase(it);
            }
            else
                printf("0\n");
            /*
            while(!q.empty() && q.top().time <= i){
                if(q.top().type == 2){
                    q.pop();
                }
                else if(q.top().type == 3){
                    HAT tmp = q.top();
                    q.pop();
                    tmp.w = tmp.x;
                    tmp.type = 1;
                    tmp.time = 10000000;
                    q.push(tmp);
                }
            }
            if(!q.empty()){
                printf("%d\n", q.top().v);
                q.pop();
            }
            else
                printf("0\n");
            */
        }
        changeType3(i);
        /*
        printf("TIME %d: ", i);
        T.inOrder(T.root);
        printf("\n\n");
        //*/
    }
    return 0;
}
/*
5 4
1 1 10 20
1 2 30 10 3
2
2
1 3 40 20 7 5
1 1 30 30
1 2 25 50 7
2
2
*/
