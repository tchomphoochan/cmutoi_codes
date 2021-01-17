#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
    bool operator()(const pair<int, int> &A, const pair<int, int> &B){
        if(A.first == B.first)
            return !(A.second > B.second);
        else
            return !(A.first<B.first);
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;

int main(){
    int N, M;
    char opr[5];
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N+M; ++i){
        int w, v;
        scanf("%s", opr);
        if(opr[0] == 'T'){
            scanf("%d%d", &w, &v);
            q.push(make_pair(w, v));
        }
        else if(opr[0] == 'P'){
            if(!q.empty()){
                printf("%d\n", q.top().second);
                q.pop();
            }
            else
                printf("0\n");
        }
    }
    return 0;
}
