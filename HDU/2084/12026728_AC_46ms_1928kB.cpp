#include<stdio.h>
int max(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int num[101][101]={0};
		int n;
		int i,j;
		scanf("%d",&n);
		for(i=0; i<n; i++)
			for(j=0; j<=i; j++)
				scanf("%d",&num[i][j]);
		int va[101][101]={0};
		for(i=n-1; i>=0; i--)
			for(j=0; j<=i; j++)
				va[i][j]=max(va[i+1][j],va[i+1][j+1])+num[i][j];
		printf("%d\n",va[0][0]);
	}
	return 0;
}