#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int, int> > q;
int broken[100005];

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    int x;
    for(int i = 1; i <= N; ++i){
        scanf("%d", &x);
        q.push(make_pair(x, i));
    }
    for(int i = 1; i <= M; ++i){
        scanf("%d", &x);
        int brokenNow = 0;
        while(!q.empty() && broken[q.top().second] && broken[q.top().second] < i)
            q.pop();
        while(!q.empty() && q.top().first > x){
            int pos = q.top().second;
            if(broken[pos] && broken[pos] < i)
                q.pop();
            else{
                //printf("(%d, %d) ", q.top().first, pos);
                if(broken[pos] == 0){
                    brokenNow++;
                    broken[pos] = i;
                }
                if(pos-1 >= 1 && broken[pos-1] == 0){
                    brokenNow++;
                    broken[pos-1] = i;
                }
                if(pos+1 <= N && broken[pos+1] == 0){
                    brokenNow++;
                    broken[pos+1] = i;
                }
                q.pop();
            }
        }
        //printf("\n");
        printf("%d\n", brokenNow);
    }
    return 0;
}
