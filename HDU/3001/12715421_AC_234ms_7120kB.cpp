#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int dp[60000][12]={0};
int num[60000][12]={0};
int map[15][15]={0};
int bit[12]={1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
void handle()
{
	for (int i=0; i<59049; i++)
	{
		int b=i;
		for(int j=0; j<10; j++)
		{
			num[i][j]=b%3;
			b/=3;
		}
	}
}

int main()
{
	handle();
	int n,m;
	while (scanf("%d%d",&n, &m)!=EOF)
	{
		memset(map, INF, sizeof(map));
		memset(dp, INF, sizeof(dp));
		for (int i=0; i<m; i++)
		{
			int a,b,val;
			scanf("%d%d%d",&a, &b, &val);
			if (map[a-1][b-1]==INF)
				map[b-1][a-1]=map[a-1][b-1]=val;
			else
				map[a-1][b-1]=map[b-1][a-1]=min(val, map[a-1][b-1]);
		}

		for (int i=0; i<n; i++)
			dp[bit[i]][i]=0;
		int ans=INF;

		for (int i=0; i<bit[n]; i++)
		{
			int flag=1;
			for(int j=0; j<n; j++)
			{
				if(num[i][j]==0)
					flag=0;
				if(dp[i][j]==INF)
					continue;
				for(int l=0; l<n; l++)
				{
					if(l==j)
						continue;
					if(num[i][l]>=2)
						continue;
					if(map[j][l]==INF)
						continue;
					int next=i+bit[l];
					dp[next][l]=min(dp[next][l], dp[i][j]+map[j][l]);
				}
			}
			if(flag)
			{
				for(int j=0; j<n; j++)
					ans=min(ans, dp[i][j]);
			}
		}
		if(ans==INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}