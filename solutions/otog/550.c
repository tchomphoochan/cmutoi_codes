#define f(i,n) for(i=0;i<n;++i)
main(n,i,j,k,x,y,p){scanf("%d",&n);f(i,n){f(j,n){p=1;f(k,10)x=(i>>k)%2,y=(j>>k)%2,x&1&&y&1?p=0:0;x=i%4;y=j%4;printf(p&&!x|!y|x==3-y?"#":".");}printf("\n");}}