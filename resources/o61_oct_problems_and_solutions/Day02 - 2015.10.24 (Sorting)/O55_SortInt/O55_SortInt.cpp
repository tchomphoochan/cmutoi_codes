#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0 ; i < N; ++i){
        int x;
        scanf("%d", &x);
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < N; ++i)
        printf("%d\n", vec[i]);
    return 0;
}
