#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 1000000000
using namespace std;

int H[100005], X[100005];
vector<int> firGroup, secGroup;
int findH(int a){
    if(H[a] == a)
        return a;
    return H[a] = findH(H[a]);
}

int main(){
    int V, E;
    scanf("%d", &V);
    E = V-2;
    for(int i = 1; i <= V; ++i){
        scanf("%d", &X[i]);
        H[i] = i;
    }
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        int hX = findH(x), hY = findH(y);
        H[hX] = H[hY];
    }
    int fir = findH(H[1]);
    for(int i = 1; i <= V; ++i){
        //printf("H(%d): %d\n", i, findH(H[i]));
        if(findH(H[i]) == fir)
            firGroup.push_back(X[i]);
        else
            secGroup.push_back(X[i]);
    }
    sort(firGroup.begin(), firGroup.end());
    sort(secGroup.begin(), secGroup.end());
    int i = 0, j = 0;
    int mi = INF;
    while(i < firGroup.size() && j < secGroup.size()){
        //printf("%d %d\n", i, j);
        mi = min(mi, abs(firGroup[i]-secGroup[j]));
        if(secGroup[j] < firGroup[i])
            j++;
        else if(firGroup[i] <= secGroup[j])
            i++;
    }
    /*
    int idx = min(firGroup.size(), secGroup.size());
    int mi = INF;
    for(int i = 0; i < idx; ++i)
        mi = min(mi, abs(firGroup[i]-secGroup[i]));
    */
    printf("%d", mi);
    return 0;
}
/*
5
10
20
40
50
80
1 3
2 5
5 4

9
80
20
30
40
50
10
35
78
90
1 2
2 3
3 4
4 5
6 7
7 8
8 9
*/
