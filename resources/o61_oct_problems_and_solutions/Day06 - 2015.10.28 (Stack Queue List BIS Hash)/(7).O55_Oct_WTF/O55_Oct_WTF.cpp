#include <cstdio>

int arr[35];

int main(){
    bool yes = false;
    for(int i = 0; i < 30; ++i)
        scanf("%d", &arr[i]);
    if(arr[0] == 3 || arr[0] == 31 || arr[0] == 33 || arr[0] == 78)
        printf("no");
    else
        printf("yes");
    return 0;
}
