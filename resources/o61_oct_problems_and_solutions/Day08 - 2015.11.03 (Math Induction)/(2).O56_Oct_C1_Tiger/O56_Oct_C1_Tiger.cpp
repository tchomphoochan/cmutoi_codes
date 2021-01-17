#include <cstdio>
#include <algorithm>
#include <map>
#define INF 1000000000
using namespace std;

pair<int, int> Fire[1005];
map<int, int> hah;

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; ++i)
        scanf("%d%d", &Fire[i].first, &Fire[i].second);
    for(int i = 0; i < M; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        int mi = INF;
        for(int j = 0; j < N; ++j){
            mi = min(mi, abs(x-Fire[j].first)+abs(y-Fire[j].second));
        }
        hah[mi]++;
    }
    int ma = 0;
    for(map<int, int>::iterator it = hah.begin(); it != hah.end(); ++it)
        ma = max(ma, it->second);
    printf("%d", ma);
    return 0;
}
