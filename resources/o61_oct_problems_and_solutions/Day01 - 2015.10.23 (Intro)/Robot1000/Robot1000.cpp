#include <cstdio>

char inp[105];

int main(){
    int x = 0, y = 0, cnt = 0;
    scanf("%s", inp);
    for(int i = 0; inp[i] != NULL; ++i){
        if(inp[i] == 'N')
            y++;
        else if(inp[i] == 'S')
            y--;
        else if(inp[i] == 'E')
            x++;
        else if(inp[i] == 'W')
            x--;
        else if(inp[i] == 'Z'){
            x = 0;
            y = 0;
        }
    }
    printf("%d %d", x, y);
    return 0;
}
