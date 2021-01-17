#include <stdio.h>

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int a[50005],b[50005];
	int v;
	for(int i = 0;i<n;++i){
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i = 0;i<m;++i){
		scanf("%d",&v);
		for(int j = 0;j<n;++j){
			if(a[j] <= v){
				int temp = a[j];
				a[j] = b[j];
				b[j] = temp;
			}
		}
	}
	for(int i = 0;i<n;++i){
		printf("%d\n",a[i]);
	}
}