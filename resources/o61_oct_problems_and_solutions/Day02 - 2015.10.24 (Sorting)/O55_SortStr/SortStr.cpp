#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> vec;
char inp[100005];

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%s", inp);
        vec.push_back(string(inp));
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < N; ++i){
        cout << vec[i];
        printf("\n");
    }
    return 0;
}
