#include<stdio.h>
#include<string.h>
int n,m;
int arr[20][20]={0};
int ans[20][20]={0};
int tmp[20][20]={0};
int dis[4][2]={0,1,0,-1,0,0,-1,0};
int getcolo(int x, int y)
{
	int c=arr[x][y];
	for(int i=0; i<4; i++)
	{
		int na=x+dis[i][0];
		int ny=y+dis[i][1];
		if(na>=0&&ny>=0&&na<n&&ny<m)
			c+=tmp[na][ny];
	}
	return c & 1;
}
int dfs(int k)
{
	if(k==n-1)
	{
		int i;
		for(i=0; i<m; i++)
		{
			if(getcolo(k,i))
				break;	
		}
		if(i!=m)
			return 999999999;
		int sum=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(tmp[i][j])
					sum++;
		return sum;
	}
	for(int j=0; j<m ;j++)
		if(getcolo(k,j))
			tmp[k+1][j]=1;
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
		int vis;
		for(int i=0; i<max; i++)
		{
			memset(tmp, 0, sizeof(tmp));
			for(int j=m-1,vis=i; j>=0; j--,vis>>=1)
				tmp[0][j]=vis&1;
			int time=dfs(0);
			if(time<min)
			{
				min=time;
				memcpy(ans, tmp, sizeof(tmp));
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