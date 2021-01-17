#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int N;
long long K;

long long PROCESS(long long day){
    long long tree = (day+1)*(day+1);
    for(int i = 1; i < N; ++i){
        if(arr[i] == arr[i-1])
            continue;
        tree+=((day+1)*(day+1));
        long long diff = arr[i]-arr[i-1];
        if(diff <= 2*day){
            long long m = day-(diff-1)/2;
            if(diff%2 == 1){
                tree-=(m*(m+1));
            }
            else if(diff%2 == 0){
                tree-=(m*m);
            }
        }
    }
    //printf("T: %lld\n", tree);
    return tree;
}

int main(){
    scanf("%d%lld", &N, &K);
    for(int i = 0; i < N; ++i){
        int x;
        scanf("%d", &x);
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    long long L = 1, idx = 0, mid;
    long long R = (long long)(sqrt(K)) + 1000;
    while(L <= R){
        mid = (L+R)/2;
        long long tree = PROCESS(mid);
        //printf("%lld->%lld\n", mid, tree);
        if(tree >= K){
            idx = mid;
            R = mid-1;
        }
        else if(tree < K){
            L = mid+1;
        }
    }
    printf("%lld", idx);
    return 0;
}
/*
4 1114
10 1 500000 1000000

3 99
10 11 12
*/
