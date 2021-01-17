#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#define INF 1000000000
using namespace std;

map<string, int> hah;
char out[155][45], dev[155][45];

int main(){
    //freopen("A-large-practice.in", "r", stdin);
    //freopen("A-large-practice.out", "w", stdout);
    int totalCase, N, L;
    scanf("%d", &totalCase);
    for(int T = 1; T <= totalCase; ++T){
        hah.clear();
        scanf("%d%d", &N, &L);
        int sum = ((N+1)*N) / 2;
        for(int i = 1; i <= N; ++i)
            scanf("%s", out[i]);
        for(int i = 1; i <= N; ++i)
            scanf("%s", dev[i]);
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                char diff[45];
                for(int k = 0; k < L; ++k){
                    if(out[i][k] != dev[j][k])
                        diff[k] = '1';
                    else
                        diff[k] = '0';
                }
                diff[L] = NULL;
                hah[string(diff)]+=i;
            }
        }
        int mi = INF;
        for(map<string, int>::iterator it = hah.begin(); it != hah.end(); ++it){
            if(it->second == sum){
                int cntDiff = 0;
                for(int i = 0; i < L; ++i){
                    if(it->first[i] == '1')
                        cntDiff++;
                }
                mi = min(mi, cntDiff);
            }
        }
        printf("Case #%d: ", T);
        if(mi == INF)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", mi);
    }
    return 0;
}
