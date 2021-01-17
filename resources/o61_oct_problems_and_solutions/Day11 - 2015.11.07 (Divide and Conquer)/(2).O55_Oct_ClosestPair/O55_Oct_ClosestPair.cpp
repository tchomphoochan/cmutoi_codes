#include <cstdio>
#include <vector>
#include <algorithm>
#define x first
#define y second
using namespace std;

pair<long long, long long> coor[100005];
long long dist(int a, int b){
    //printf("%d(%lld,%lld) & %d(%lld,%lld) == (%lld)\n", a, coor[a].x, coor[a].y, b, coor[b].x, coor[b].y, (coor[a].x-coor[b].x)*(coor[a].x-coor[b].x) + (coor[a].y-coor[b].y)*(coor[a].y-coor[b].y));
    return (coor[a].x-coor[b].x)*(coor[a].x-coor[b].x) + (coor[a].y-coor[b].y)*(coor[a].y-coor[b].y);
}


long long findClosestPair(int L, int R){
    //printf("%d->%d\n", L, R);
    if(L == R)
        return 10000000000000;
    else if(R-L == 1)
        return dist(L, R);
    else if(R-L == 2)
        return min(dist(L, L+1), min(dist(L+1, R), dist(L, R)));
    int mid = (L+R)/2;
    long long delta = min(findClosestPair(L, mid), findClosestPair(mid+1, R));
    //printf("DELTA: %lld\n", delta);
    int Line = coor[mid].x;
    int x1 = Line-delta, x2 = Line+delta;
    for(int i = L; i <= R; ++i){
        if(coor[i].x >= x1 && coor[i].x <= x2){
            for(int j = i+1; j <= min(i+7, R) && coor[j].x <= x2; ++j){
                delta = min(delta, dist(i, j));
            }
        }
        else if(coor[i].x > x2)
            break;
    }
    return delta;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%lld%lld", &coor[i].x, &coor[i].y);
    sort(coor, coor+N);
    printf("%lld", findClosestPair(0, N-1));
    return 0;
}
/*
4
0 0
10 10
5 0
4 3
*/
