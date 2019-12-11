#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char num[1005][1005]={0};
int h[1005][1005]={0};
int cmp(const void *a, const void *b)
{
	return *(int*)b-*(int*)a; 
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int ans=0;
		for(int i=1; i<=n; i++)
			scanf("%s",num[i]+1);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
			{
				if(num[i][j]=='1')
					h[i][j]=h[i-1][j]+1;
				if(num[i][j]=='0')	
					h[i][j]=0;
			}
		for(int i=1; i<=n; i++)
		{
			qsort(h[i]+1, m, sizeof(int), cmp);
			for(int j=1; j<=m; j++)
				ans=ans>h[i][j]*j ? ans:h[i][j]*j;
		}
		printf("%d\n",ans);
		memset(h, 0, sizeof(h));
		memset(num, 0, sizeof(num));
	}
	return 0;
}