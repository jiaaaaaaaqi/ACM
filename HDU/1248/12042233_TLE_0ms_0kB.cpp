#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int m;
	int T;
	int bp[1000]={0};
	int a[4]={0,150,200,350};
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&m);
		int i,j,k;
		for(i=1; i<=3; i++)
		{
			for(j=1; j<=m; j++)
				if(j>=a[i])
					bp[j]=max(bp[j], bp[j-a[i]]+a[i]);
		}
		printf("%d\n",m-bp[m]);
		memset(bp, 0, sizeof(bp));
	}
	return 0;
}
