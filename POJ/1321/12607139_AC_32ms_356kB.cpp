#include<stdio.h>
#include<string.h>
int n,ans;
char str[15][15]={0};
int vis[105]={0};
void dfs(int x, int time)
{
	if(x>n)
		return ;
	if(time==0)
	{
		ans++;
		return ;
	}
	for(int i=x; i<n; i++)
		for(int j=0; j<n; j++)
			if(str[i][j]=='#'&&vis[j]==0)
			{
				vis[j]=1;
				dfs(i+1, time-1);
				vis[j]=0;
			}
}
int main()
{
	int time;
	while(scanf("%d%d",&n,&time), n!=-1||time!=-1)
	{
		ans=0;
		for(int i=0; i<n; i++)
			scanf("%s",str[i]);
		dfs(0, time);
		printf("%d\n",ans);
		memset(vis, 0, sizeof(vis));
		memset(str, 0, sizeof(str));
	}
	return 0;
}