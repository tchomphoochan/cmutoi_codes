#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char A[305], B[305], C[605];
vector<int> ans;

int main(){
    scanf("%s%s%s", A, B, C);
    int lenA = strlen(A), lenB = strlen(B), lenC = strlen(C);
    int st = 0;
    for(int i = lenA-1; i >= 0; --i){
        int idx = st;
        for(int j = lenB-1; j >= 0; --j){
            int now = (A[i]-'0')*(B[j]-'0');
            if(ans.size() == idx)
                ans.push_back(now);
            else
                ans[idx]+=now;
            idx++;
        }
        st++;
    }
    for(int i = 0; i < ans.size()-1; ++i){
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    while(ans[ans.size()-1] >= 10){
        ans.push_back(ans[ans.size()-1]/10);
        ans[ans.size()-2]%=10;
    }
    bool truth = true;
    if(ans.size() != lenC)
        truth = false;
    else{
        for(int i = ans.size()-1, j = 0; i >= 0 && truth; --i, ++j)
            if(ans[i] != C[j]-'0')
                truth = false;
    }
    if(truth)
        printf("truth");
    else
        printf("dream");
    return 0;
}
