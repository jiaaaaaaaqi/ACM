#include<stdio.h>
#include<string.h>
int n,m;
int arr[20][20]={0};
int ans[20][20]={0};
int vis[20][20]={0};
int tmp[20][20]={0};
void change(int x, int y)
{
	tmp[x][y]=1-tmp[x][y];
	if(x-1>=0)
		tmp[x-1][y]=1-tmp[x-1][y];
	if(y-1>=0)
		tmp[x][y-1]=1-tmp[x][y-1];
	if(x+1<n)
		tmp[x+1][y]=1-tmp[x+1][y];
	if(y+1<m)
		tmp[x][y+1]=1-tmp[x][y+1];
}
int dfs(int k)
{
	if(k==n)
	{
		int time=0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				time+=vis[i][j];
				if(tmp[i][j])
					return 999999999;
			}
		}
		return time;
	}
	for(int j=0; j<m; j++)
	{
		if(tmp[k-1][j])
		{
			change(k,j);
			vis[k][j]=1;
		}
	}
	return dfs(k+1);
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int min=999999999;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d",&arr[i][j]);
		int max=1<<m;
		for(int i=0; i<max; i++)
		{
			memcpy(tmp, arr, sizeof(arr));
			memset(vis, 0, sizeof(vis));
			for(int j=0; j<m; j++)
			{
				if(i&(1<<j))
				{
					change(0,j);
					vis[0][j]=1;
				}
			}
			int time=dfs(0);
			if(time<min)
			{
				min=time;
				memcpy(ans, vis, sizeof(vis));
			}
		}
		if(min==999999999)
			printf("IMPOSSIBLE\n");
		else
		{
			for(int i=0; i<n; i++)
				for(int j=0; j<m; j++)
					printf("%d%c",ans[i][j], (j==m-1 ? '\n':' '));
		}
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}