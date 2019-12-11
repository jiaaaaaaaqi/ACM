#include<stdio.h>
int max(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int c[1003]={0};		//价值 
		int w[1003]={0};		//费用 
		int va[1003]={0};
		int n,v,i,j;			//v 总费用 
		scanf("%d%d",&n, &v);
		for(i=1; i<=n; i++)
			scanf("%d",&c[i]);	
		for(i=1; i<=n; i++)
			scanf("%d",&w[i]);
		for(i=1; i<=n; i++)
			for(j=v; j>=w[i]; j--)
				va[j]=max(va[j],va[j-w[i]]+c[i]);
		printf("%d\n",va[v]);
	}
	return 0;
}