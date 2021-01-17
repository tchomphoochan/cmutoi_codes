#include <cstdio>
#include <algorithm>
#include <vector>
#define SIZE 10000
#define INF 100000000
using namespace std;

class BOX{
public:
    int x1, y1, x2, y2;
    BOX(int x1, int y1, int x2, int y2){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
};
vector<BOX> box;
vector<pair<int, int> > query;
vector<int> vec, vec2;
int FT[SIZE+5][SIZE+5];

void update(int x, int y, int val){
    int tmpy = y;
    while(x <= vec.size()+1){
        y = tmpy;
        while(y <= vec2.size()+1){
            FT[x][y]+=val;
            y+=(y&(-y));
        }
        x+=(x&(-x));
    }
}
int sumTo(int x, int y){
    int sum = 0;
    int tmpy = y;
    while(x >= 1){
        y = tmpy;
        while(y >= 1){
            sum+=FT[x][y];
            y-=(y&(-y));
        }
        x-=(x&(-x));
    }
    return sum;
}
int bis1(int L, int R, int fnd){
    int idx, mid;
    while(L <= R){
        mid = (L+R)/2;
        if(vec[mid] <= fnd){
            idx = mid;
            L = mid+1;
        }
        else
            R = mid-1;
    }
    return idx;
}
int bis2(int L, int R, int fnd){
    int idx, mid;
    while(L <= R){
        mid = (L+R)/2;
        if(vec2[mid] <= fnd){
            idx = mid;
            L = mid+1;
        }
        else
            R = mid-1;
    }
    return idx;
}
void manageArr(){
    sort(vec.begin()+1, vec.end());
    sort(vec2.begin()+1, vec2.end());
    for(int i = 2; i < vec.size(); ++i){
        int tmpi = i;
        while(vec[tmpi] == vec[i-1])
            vec[tmpi++] = INF;
        i = tmpi;
    }
    for(int i = 2; i < vec2.size(); ++i){
        int tmpi = i;
        while(vec2[tmpi] == vec2[i-1])
            vec2[tmpi++] = INF;
        i = tmpi;
    }
    sort(vec.begin()+1, vec.end());
    sort(vec2.begin()+1, vec2.end());
    for(int i = vec.size()-1; vec[i] == INF; --i)
        vec.pop_back();
    for(int i = vec2.size()-1; vec2[i] == INF; --i)
        vec2.pop_back();
    vec.push_back(100001);
    vec2.push_back(100001);
}

int main(){
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    vec.push_back(-1);
    vec2.push_back(-2);
    vec.push_back(0);
    vec2.push_back(0);
    for(int i = 0; i < N; ++i){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1++, y1++, x2++, y2++;
        box.push_back(BOX(x1, y1, x2, y2));
    }
    for(int i = 0; i < M; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        x++, y++;
        vec.push_back(x);
        vec2.push_back(y);
        query.push_back(make_pair(x, y));
    }
    manageArr();
    for(int i = 0; i < box.size(); ++i){
        int X1 = lower_bound(vec.begin()+1, vec.end(), box[i].x1)-vec.begin();
        int X2 = bis1(1, (int)vec.size()-1, box[i].x2);
        int Y1 = lower_bound(vec2.begin()+1, vec2.end(), box[i].y1)-vec2.begin();
        int Y2 = bis2(1, (int)vec2.size()-1, box[i].y2);
        update(X1, Y1, 1);
        update(X1, Y2+1, -1);
        update(X2+1, Y1, -1);
        update(X2+1, Y2+1, 1);

    }
    for(int i = 0; i < M; ++i){
        int X = lower_bound(vec.begin()+1, vec.end(), query[i].first)-vec.begin();
        int Y = lower_bound(vec2.begin()+1, vec2.end(), query[i].second)-vec2.begin();
        printf("%d\n", sumTo(X, Y));
    }
    return 0;
}
/*
#include <cstdio>
#define SIZE 10000

int FT[SIZE+2][SIZE+2], N;

void update(int x, int y, int val){
    int tmpy = y;
    while(x <= SIZE){
        y = tmpy;
        while(y <= N){
            FT[x][y]+=val;
            y+=(y&(-y));
        }
        x+=(x&(-x));
    }
}

int sumTo(int x, int y){
    int sum = 0;
    int tmpy = y;
    while(x >= 1){
        y = tmpy;
        while(y >= 1){
            sum+=FT[x][y];
            y-=(y&(-y));
        }
        x-=(x&(-x));
    }
    return sum;
}

int main(){
    int M, K;
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 0; i < N; ++i){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1++, y1++, x2++, y2++;
        update(x1, y1, 1);
        update(x1, y2+1, -1);
        update(x2+1, y1, -1);
        update(x2+1, y2+1, 1);
    }
    while(M--){
        int x, y;
        scanf("%d%d", &x, &y);
        x++, y++;
        printf("%d\n", sumTo(x, y));
    }
    return 0;
}
*/
/*
10 5 3
3 0 8 2
1 7 8 9
1 0 8 2
5 2 6 4
5 1 5 4
7 3 7 9
0 0 0 3
6 2 6 4
8 3 9 8
4 4 8 6
7 9
8 5
3 0
6 4
3 4
*/
