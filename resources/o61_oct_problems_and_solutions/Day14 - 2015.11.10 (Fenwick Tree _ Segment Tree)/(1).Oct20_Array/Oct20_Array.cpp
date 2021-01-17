#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#define notHave -1200000000
#define SIZE 200000
using namespace std;

class NODE{
public:
    int st, en;
    long long val;
    NODE(){}
    NODE(int st, int en, long long val){
        this->st = st;
        this->en = en;
        this->val = val;
    }
};
class QUERY{
public:
    int a, b, v, type;
    QUERY(int type, int a, int b, int v){
        this->type = type;
        this->a = a;
        this->b = b;
        this->v = v;
    }
};

long long ST[4*SIZE+5];
int Lazy[4*SIZE+5];
vector<QUERY> qu;
vector<int> interval;

void build(int idx, int L, int R){
    Lazy[idx] = notHave;
    if(L == R){
        ST[idx] = 0;
        return;
    }
    int mid = (L+R)/2;
    build(idx*2, L, mid);
    build(idx*2+1, mid+1, R);
    ST[idx] = ST[idx*2]+ST[idx*2+1];
}
void upd(int idx, int L, int R, int v){
    int st = interval[L], en = interval[R+1];
    Lazy[idx] = v;
    ST[idx] = ((long long)(en-st)*v);
    //printf("ADD %d [%d-%d) (%d)\n", idx, ST[idx].st, ST[idx].en, v);
    return;
}
void shift(int idx, int L, int R){
    if(Lazy[idx] == notHave)
        return;
    int mid = (L+R)/2;
    upd(idx*2, L, mid, Lazy[idx]);
    upd(idx*2+1, mid+1, R, Lazy[idx]);
    Lazy[idx] = notHave;
}
void update(int idx, int L, int R, int x, int y, int v){
    int st = interval[L], en = interval[R+1];
    if(en < x || y < st)
        return;
    if(x <= st && en <= y){
        upd(idx, L, R, v);
        return;
    }
    if(L == R)
        return;
    int mid = (L+R)/2;
    shift(idx, L, R);
    update(idx*2, L, mid, x, y, v);
    update(idx*2+1, mid+1, R, x, y, v);
    ST[idx] = ST[idx*2] + ST[idx*2+1];
}
long long query(int idx, int L, int R, int x, int y){
    int st = interval[L], en = interval[R+1];
    if(en < x || y < st)
        return 0;
    if(x <= st && en <= y){
        //printf("[%d-%d) (%lld)\n", st, en, ST[idx].val);
        return ST[idx];
    }
    if(L == R)
        return 0;
    shift(idx, L, R);
    int mid = (L+R)/2;
    return query(idx*2, L, mid, x, y) + query(idx*2+1, mid+1, R, x, y);
}
void printS(int idx, int L, int R){
    printf("%d(%d->%d) = [%d-%d) (%d)\n", idx, L, R, interval[L], interval[R+1], ST[idx]);
    if(L == R)
        return;
    int mid = (L+R)/2;
    printS(idx*2, L, mid);
    printS(idx*2+1, mid+1, R);
}
int main(){
    int N, Q;
    scanf("%d%d", &N, &Q);
    interval.push_back(-1);
    for(int i = 0; i < Q; ++i){
        int opr, a, b, v = 0;
        scanf("%d%d%d", &opr, &a, &b);
        if(opr == 0)
            scanf("%d", &v);
        interval.push_back(a);
        interval.push_back(b);
        qu.push_back(QUERY(opr, a, b, v));
    }
    sort(interval.begin()+1, interval.end());
    for(int i = 2; i < interval.size(); ++i){
        int tmpi = i;
        while(interval[tmpi] == interval[i-1])
            interval[tmpi++] = INT_MAX;
        i = tmpi;
    }
    sort(interval.begin()+1, interval.end());
    for(int i = interval.size()-1; interval[i] == INT_MAX && i >= 0; --i)
        interval.pop_back();
    int inSize = interval.size()-2;
    /*
    for(int i = 1; i < interval.size(); ++i)
        printf("%d ", interval[i]);
    printf("\n");
    //*/
    build(1, 1, inSize);
    //printS(1, 1, inSize);
    for(int i = 0; i < Q; ++i){
        int a = qu[i].a, b = qu[i].b, type = qu[i].type, v = qu[i].v;
        if(type == 0){
            //printf("->UPDATE %d to %d(%d)\n", a, b, v);
            update(1, 1, inSize, a, b, v);
            //printf("\n");
        }
        else if(type == 1){
            //printf("->QUERY %d to %d\n", a, b);
            printf("%lld\n", query(1, 1, inSize, a, b));
        }
    }
    return 0;
}
/*
2000000000
2
0 0 2000000000 1000000
1 0 2000000000

10
6
1 0 10
0 0 5 1
1 0 10
0 5 10 2
1 0 10
1 3 8
*/
