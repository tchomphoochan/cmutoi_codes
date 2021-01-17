#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> q;

int main(){
    int N, L, H;
    scanf("%d%d%d", &N, &L, &H);
    while(N--){
        int n;
        scanf("%d", &n);
        while(n--){
            int x;
            scanf("%d", &x);
            q.push(x);
        }
        int x, y;
        double pos;
        scanf("%d%d", &x, &y);
        pos = (double)x * ((double)H/y);
        pos = (double)L+pos;
        while(!q.empty() && q.top() >= pos)
            q.pop();
        printf("%d\n", q.size());
    }
    return 0;
}
/*
3 10 5
4 1 2 3 4 -1 1
2 11 12 0 1
0 -7 5
*/
