#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
    bool operator()(const int& A, const int& B){
        return !(A < B);
    }
};
priority_queue<int, vector<int>, cmp> q[105];

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    while(M--){
        int x, time;
        scanf("%d%d", &x, &time);
        q[x].push(time);
    }
    int sum = 0;
    for(int i = 1; i <= N; ++i)
        sum+=q[i].top();
    printf("%d\n", sum);
    for(int i = 1; i <= N; ++i)
        printf("%d %d\n", i, q[i].top());
    return 0;
}
