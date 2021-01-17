#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	if(n%2 == 0){
		printf("error");
		return 0;
	}
	int mid = (n/2)+1;
	int l = 1;
	int r = n;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			if(j >= l and j <= r) printf("*");
			else printf(" ");
		}
		if(i != n) printf("\n");
		if(i < mid){
			++l;
			--r;
		}
		else{
			--l;
			++r;
		}
	}
}