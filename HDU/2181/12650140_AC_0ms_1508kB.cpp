#include<stdio.h>
#include<string.h>
int  map[30][30];
int vis[30];
int ans[30];
int cas;
void dfs(int x, int cnt)
{
	if(cnt==20)
	{
		if(map[x][ans[1]])
		{
			printf("%d:  ", cas++);
			for(int i=1; i<=20; i++)
				printf("%d ", ans[i]);
			printf("%d\n",ans[1]);
		} 
	}
	for(int i=1; i<=20; i++)
	{
		if(map[x][i]&&!vis[i])
		{
			vis[i]=1;
			ans[cnt+1]=i;
			dfs(i, cnt+1);
			vis[i]=0;
		}
	}
}
int main()
{
	memset(map, 0, sizeof(map));
	for(int i=1; i<=20; i++)
	{
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		map[i][a]=1;
		map[i][b]=1;
		map[i][c]=1;
	}
	int n;
	while(scanf("%d",&n),n)
	{
		cas=1;
		memset(vis, 0, sizeof(vis));
		memset(ans, 0, sizeof(ans));
		vis[n]=1;
		ans[1]=n;
		dfs(n, 1);
	}
	return 0;
}