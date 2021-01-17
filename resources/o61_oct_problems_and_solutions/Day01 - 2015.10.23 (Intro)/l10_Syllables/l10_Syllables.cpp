#include <cstdio>

char inp[35];
bool vowel(char x){
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return true;
    else
        return false;
}

int main(){
    int N;
    scanf("%d", &N);
    while(N--){
        int syllables = 0;
        scanf("%s", inp);
        for(int i = 0; inp[i] != NULL; ++i){
            if(vowel(inp[i])){
                syllables++;
                while(vowel(inp[i]))
                    ++i;
                --i;
            }
        }
        printf("%d\n", syllables);
    }
    return 0;
}
