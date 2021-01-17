#include <cstdio>
#include <vector>
#include <algorithm>
#define st first
#define en second
using namespace std;

vector<pair<int, int> > vec;
bool cmp(const pair<int, int> &A, const pair<int, int> &B){
    if(A.st == B.st)
        return A.en < B.en;
    else
        return A.st < B.st;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        vec.push_back(make_pair(x, y));
    }
    sort(vec.begin(), vec.end(), cmp);
    int longMilk = vec[0].en-vec[0].st, longNoMilk = 0, ST = vec[0].st, EN = vec[0].en;
    for(int i = 1; i < N; ++i){
        if(vec[i].st <= EN)
            EN = max(EN, vec[i].en);
        else{
            longNoMilk = max(longNoMilk, vec[i].st-EN);
            ST = vec[i].st;
            EN = vec[i].en;
        }
        //printf("ST: %d EN: %d\n", ST, EN);
        longMilk = max(longMilk, EN-ST);
        //printf("%d %d\n", vec[i].st, vec[i].en);
    }
    printf("%d %d", longMilk, longNoMilk);
    return 0;
}
/*
5
6000 9000
1100 2000
1000 2000
1900 4000
1 1000

3
1 6
6 25
4 30

4
1 6
6 25
4 30
60 1000
*/
