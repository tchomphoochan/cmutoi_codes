#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> me, com;
bool cmp(const int &A, const int &B){
    return A > B;
}

int main(){
    int N, x;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &x);
        me.push_back(x);
    }
    for(int i = 0; i < N; ++i){
        scanf("%d", &x);
        com.push_back(x);
    }
    sort(me.begin(), me.end(), cmp);
    sort(com.begin(), com.end(), cmp);
    int backMe = N-1, frontCom = 0, frontMe = 0, strength = 0;
    while(frontMe <= backMe){
        if(me[frontMe] <= com[frontCom]){
            backMe--;
            frontCom++;
        }
        else{
            strength+=me[frontMe++];
            frontCom++;
        }
    }
    printf("%d", strength);
    return 0;
}
