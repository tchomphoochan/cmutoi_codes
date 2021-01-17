#include <stdio.h>
bool check[1005][1005]={0};

int main()
{
	int N,x,y;
	int i,count=0;
	scanf("%d",&N);

	for(i=0;i<N;i++)
	{
		scanf("%d %d",&x,&y);
		if(check[x][y]==0)
		{
			check[x][y]=1;
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}