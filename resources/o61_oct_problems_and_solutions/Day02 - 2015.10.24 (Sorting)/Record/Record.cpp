#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

map<set<string>, int> hah;

int main(){
    int N;
    char inp[15];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        set<string> inpSet;
        for(int j = 0; j < 3; ++j){
            scanf("%s", &inp);
            inpSet.insert(inp);
        }
        hah[inpSet]++;
    }
    int ma = 0;
    for(map<set<string>, int>::iterator it = hah.begin(); it != hah.end(); ++it)
        ma = max(ma, it->second);
    printf("%d", ma);
    return 0;
}
