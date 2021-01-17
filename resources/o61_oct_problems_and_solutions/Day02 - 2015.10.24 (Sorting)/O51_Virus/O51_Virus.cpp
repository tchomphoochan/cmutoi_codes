#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nose, ear;
bool cmp(const int& A, const int& B){
    return A > B;
}

int main(){
    int N, x;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &x);
        nose.push_back(x);
    }
    for(int i = 0; i < N; ++i){
        scanf("%d", &x);
        ear.push_back(x);
    }
    sort(nose.begin(), nose.end());
    sort(ear.begin(), ear.end(), cmp);
    int maSmall = 0;
    for(int i = 0; i < N; ++i){
        int small = min(nose[i], ear[i]);
        maSmall = max(maSmall, small);
    }
    printf("%d", maSmall);
    return 0;
}
