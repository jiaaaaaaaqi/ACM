#include<stdio.h>
int max_(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int num[100]={0};
		int va[100]={0};
		int va2[100]={0};
		int i,j,z=1;
		int n;
		scanf("%d",&n);
		int n1=n;
		while(n--)
		{
			for(i=1; ; i++)
			{
				scanf("%d",&num[i]);
				if(i==z)
				{
					z++;
					break;
				}
			}
			for(j=z-1; j>=1; j--)
			{
				va[j]=max_(va[j]+num[j],va[j-1]+num[j]);
				if(n==0)
				va2[j]=va[j];
			}
	 	}
	 	int max=va2[1];
	 	for(i=2; i<=n1; i++)
	 		max=max>va2[i] ? max:va2[i];
		printf("%d\n",max);
	}
	return 0;
}