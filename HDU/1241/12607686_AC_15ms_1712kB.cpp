#include<stdio.h>
#include<string.h>
int n,m;
int oil[105][105]={0};
void dfs(int x, int y)
{
	if(oil[x][y]==0)
		return ;
	else if(x<0||x>n||y<0||y>m)
		return ;
	else
	{
		oil[x][y]=0;
		for(int i=-1; i<=1; i++)
		{
			for(int j=-1; j<=1; j++)
			{
				dfs(x+i, y+j);
			}
		}
	}
	return ;
}
int main()
{
	while(scanf("%d%d",&n,&m),m)
	{
		char preoil[105]={0};
		for(int i=0; i<n; i++)
		{
			scanf("%s",preoil); 
			for(int j=0; j<m; j++)
			{
				if(preoil[j]=='*')
					oil[i][j]=0;
				else if(preoil[j]=='@')
					oil[i][j]=1;
			}
		}
		int cnt=0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(oil[i][j]==1)
				{
					cnt++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}