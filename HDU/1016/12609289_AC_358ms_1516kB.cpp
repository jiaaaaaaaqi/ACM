#include<stdio.h>
#include<string.h>
int vis[100]={0};
int num[51]={0};
int isp[100];
int n;
void getpri()
{
	memset(isp, 1, sizeof(isp));
	isp[0]=isp[1]=0;
	for(int i=2; i<100; i++) 
		for(int j=2; i*j<100; j++)
			isp[i*j]=0;
}
void dfs(int cnt)
{
	if(cnt==n&&isp[num[n]+1])
	{
		for(int i=1; i<=n; i++)
			printf("%d%c",num[i], (i==n ? '\n':' '));
		return;
	}
	for(int i=2; i<=n; i++)
	{
		if(isp[i+num[cnt]]&&vis[i]==0)
		{
			num[cnt+1]=i;
			vis[i]=1;
			dfs(cnt+1);
			vis[i]=0;
		}
	}
}
int main()
{
	getpri();
	int cas=1;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case %d:\n", cas++);
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		num[1]=1;
		dfs(1);
		printf("\n");
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}