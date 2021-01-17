#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define SIZE 100000
#define INF 1000000000
using namespace std;

vector<int> points;
pair<int, int> arr[SIZE+5];
long long FT[2*SIZE+5];
int N;

void update(int idx, int v){
    while(idx < points.size()){
        FT[idx]+=v;
        idx+=(idx&(-idx));
    }
}

long long sumTo(int idx){
    long long sum = 0;
    while(idx >= 1){
        sum+=FT[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}

bool cmp(const pair<int, int> &A, const pair<int, int> &B){
    if(A.first == B.first)
        return A.second > B.second;
    return A.first < B.first;
}

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        scanf("%d", &N);
        points.clear();
        points.push_back(-INF);
        memset(FT, 0, sizeof(FT));
        for(int i = 1; i <= N; ++i){
            int x, R;
            scanf("%d%d", &x, &R);
            arr[i].first = x-R;
            arr[i].second = x+R;
            points.push_back(x-R);
            points.push_back(x+R);
        }
        sort(points.begin()+1, points.end());
        for(int i = 2; i < points.size(); ++i){
            int tmpi = i;
            while(points[tmpi] == points[i-1])
                points[tmpi++] = INF;
            i = tmpi;
        }
        sort(points.begin()+1, points.end());
        for(int i = points.size()-1; points[i] == INF && i >= 1; --i)
            points.pop_back();
        /*
        for(int i = 1; i < points.size(); ++i)
            printf("%d ", points[i]);
        printf("\n");
        //*/
        sort(arr+1, arr+N+1, cmp);
        long long ans = 0;
        for(int i = 1; i <= N; ++i){
            int posL = lower_bound(points.begin()+1, points.end(), arr[i].first)-points.begin();
            int posR = lower_bound(points.begin()+1, points.end(), arr[i].second)-points.begin();
            //printf("(%d, %d) Update(%d)->Update(%d) = (%d)\n", arr[i].first, arr[i].second, posL, posR, sumTo(posR-1)-sumTo(posL));
            ans+=sumTo(posR-1)-sumTo(posL);
            //update(posL, 1);
            update(posR, 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
2
3
10 10
15 10
20 10
4
10 100
20 100
30 100
40 100
*/
