#include<stdio.h>
#include<string.h> 
int vis[25][25]={0};
char str[25][25]={0};
int n,m,cnt;
void dfs(int x, int y)
{
	int dire[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
	if(x<0||y<0||x>=n||y>=m||vis[x][y])
		return ;
	if(str[x][y]=='#')
		return ;
	vis[x][y]=1;
	cnt++;
	for(int i=0; i<4; i++)
	{
		int newx=x+dire[i][0];
		int newy=y+dire[i][1];
		dfs(newx, newy);
	}
}
int main()
{
	while(scanf("%d%d",&m,&n), n||m)
	{
		cnt=0;
		int x,y;
		for(int i=0; i<n; i++)
		{
			scanf("%s",str[i]);
			for(int j=0; j<m; j++)
				if(str[i][j]=='@')
					x=i,y=j; 
		}
		dfs(x, y);
		printf("%d\n", cnt);
		memset(str, 0, sizeof(str));
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}
